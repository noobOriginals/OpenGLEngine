#include <iostream>

#include <api/window.hpp>
#include <api/shader.hpp>
#include <api/vao.hpp>
#include <api/vbo.hpp>
#include <api/texture.hpp>

#include <util/vec.h>
#include <util/geometry.h>

using namespace api;

Point3D vecs[4] = {
    geoCreatePoint3D(0.5f, 0.5f, 0.0f, 1.0f, 1.0f),
    geoCreatePoint3D(0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
    geoCreatePoint3D(-0.5f, -0.5f, 0.0f, 0.0f, 0.0f),
    geoCreatePoint3D(-0.5f, 0.5f, 0.0f, 0.0f, 1.0f),
};
uint32 idx[6] = {
    0, 1, 2,
    3, 0, 2,
};

int32 main() {
    window::useCallouts(true);
    Window window(800, 600, "GL Test");
    window.enableVSync();

    shader::useCallouts(true);
    Shader shader(shader::loadSourceFromFile("vertShader.glsl"), shader::loadSourceFromFile("fragShader.glsl"));
    shader.setInt("image", 0);

    Texture tex("tex.png");

    uint32 itt = 0;
    int64 startTime = gluGetMilliseconds();
    uint64 totalSecs = 0;

    vao::useCallouts(true);
    vbo::useCallouts(true);
    Vao vao;
    Vbo vbo(vbo::type::VBO, vecs, sizeof(vecs), 5);
    Vbo ebo(vbo::type::EBO, idx, sizeof(idx), 0);

    vao.bind();
    vbo.bind();
    vbo.vertexAttribPointer(0, 0, vbo::type::VEC3);
    vbo.vertexAttribPointer(1, VEC_SIZEOF_VEC3, vbo::type::VEC2);
    vao.unbind();
    vbo.unbind();

    bool typeLSchedule = false;
    bool wireframeEnabled = false;
    window.drawFilled();
    while (!window.shouldClose()) {
        itt++;

        window.focus();
        if (window.keyTyped(GLFW_KEY_L, typeLSchedule)) {
            if (wireframeEnabled) {
                window.drawFilled();
                wireframeEnabled = false;
            }
            else {
                window.drawWireframe();
                wireframeEnabled = true;
            }
        }

        glClearColor(0.33f, 0.66f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();
        vao.bind();
        ebo.bind();
        glActiveTexture(GL_TEXTURE0);
        tex.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        shader.stopUse();
        vao.unbind();
        window.flush();
    }

    std::cout << "\nAverage loop time is " << (float64)(gluGetMilliseconds() - startTime) / (1000 * itt) << " seconds in " << itt << " itterations\n\n";

    return 0;
}