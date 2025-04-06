// Std Includes
#include <iostream>

// API Includes
#include <api/window.hpp>
#include <api/shader.hpp>
#include <api/vao.hpp>
#include <api/vbo.hpp>
#include <api/texture.hpp>
#include <api/camera.hpp>

// API Util Includes
#include <util/geometry.h>
#include <util/types.h>
#include <util/vec.h>

// Using 'api namespace for easier use'
using namespace api;

// Create point array
// Point3D contains two vectors, one of 3 elements (x, y, z of the point) and one of 2 elements (x, y textrure coordonates of the point)
Point2D vecs[4] = {
    //                 X      Y    TexX  TexY
    geoCreatePoint2D( 0.5f,  0.5f, 1.0f, 1.0f),
    geoCreatePoint2D( 0.5f, -0.5f, 1.0f, 0.0f),
    geoCreatePoint2D(-0.5f, -0.5f, 0.0f, 0.0f),
    geoCreatePoint2D(-0.5f,  0.5f, 0.0f, 1.0f),
};
// Create point drawing idx array
uint32 idx[6] = {
    0, 1, 2, // First triangle
    3, 0, 2, // Second triangle
};

int32 run() {
    // Create a window
    // Tell the window API to use callouts
    window::useCallouts(true);
    // Create the window
    Window window(800, 600, "GL Test");
    // Enable window VSync
    window.enableVSync();

    // Create a shader
    // Tell the shader API to use callouts
    shader::useCallouts(true);
    // Create the shader
    Shader shader(shader::loadSourceFromFile("vertShader.glsl"), shader::loadSourceFromFile("fragShader.glsl"));

    // Create the texture
    Texture tex("tex.png");

    // Utility variables to measure looptimes
    uint32 itt = 0;
    int64 startTime = gluGetMilliseconds();
    uint64 totalSecs = 0;

    // Tell the VAO and VBO API's to use callouts
    vao::useCallouts(true);
    vbo::useCallouts(true);
    // Create a VAO
    Vao vao;
    // Create a VBO
    Vbo vbo(vbo::type::VBO, vecs, sizeof(vecs), 4);
    // Create an EBO
    Vbo ebo(vbo::type::EBO, idx, sizeof(idx), 0);

    // Bind the VAO so that we initialize it
    vao.bind();
    // Bind the VBO
    vbo.bind();
    // Set VBO attributes that have to be set at each VAO bind
    // Point attribute, layout = 0
    vbo.vertexAttribPointer(0, 0, vbo::type::VEC2);
    // Texture attribute, layout = 1
    vbo.vertexAttribPointer(1, VEC_SIZEOF_VEC2, vbo::type::VEC2);
    // Unbind VBO first
    vao.unbind();
    // Then unbind VAO
    vbo.unbind();

    // Other utility variables for user input
    int32 width, height;
    bool typeLSchedule = false;
    Vec2 camPos = vecCreateVec2(0.2f, 0.0f);

    Camera2D cam(vecCreateVec2(0.2f, 0.0f));

    while (!window.shouldClose()) {
        itt++;

        // Make sure to focus window, in case there are more windows open at the same time
        window.focus();
        // Check for user input
        if (window.keyTyped(GLFW_KEY_L, typeLSchedule)) {
            if (window.isWireframeEnabled()) {
                // Stop wireframe rendering
                window.drawFilled();
            }
            else {
                // Enable wireframe rendering
                window.drawWireframe();
            }
        }
        // Get key input and move camera based on it
        Vec2 dir = vecCreateVec2(0.0f, 0.0f);
        if (window.keyPressed(GLFW_KEY_W)) {
            dir.y += 1;
        }
        if (window.keyPressed(GLFW_KEY_S)) {
            dir.y -= 1;
        }
        if (window.keyPressed(GLFW_KEY_D)) {
            dir.x += 1;
        }
        if (window.keyPressed(GLFW_KEY_A)) {
            dir.x -= 1;
        }
        cam.move(dir, 0.01f);

        // Set the background color of the window
        glClearColor(0.33f, 0.66f, 1.0f, 1.0f);
        // Clear the background of the window
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw the object
        // Use the shader
        shader.use();
        // Set shader texture idx
        shader.setInt("image", 0);
        // Create projection mat3
        window.getSize(&width, &height);
        Mat3 proj = vecProjectionMat3((float) width / height);
        // Set shader uniforms
        shader.setFloatMat3("view", vecPtrMat3(cam.getViewMatrix()));
        shader.setFloatMat3("projection", vecPtrMat3(proj));
        // Bind the VAO
        vao.bind();
        // Bind the EBO
        ebo.bind();
        // Tell which texture idx is going to be used by the soon to be bound texture
        glActiveTexture(GL_TEXTURE0);
        // Bind the texture
        tex.bind();
        // Tell OpenGL to draw the object
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // Stop the use of the shader
        shader.stopUse();
        // Unbind the VAO
        vao.unbind();
        // Unbind the EBO
        ebo.unbind();
        // Refresh the window;
        window.flush();
    }

    // Tell user what are the measured looptimes
    std::cout << "\nAverage loop time is " << (float64)(gluGetMilliseconds() - startTime) / (1000 * itt) << " seconds in " << itt << " itterations\n\n";

    return 0;
}