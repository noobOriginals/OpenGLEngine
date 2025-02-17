#include <iostream>

#include <api/window.hpp>
#include <api/shader.hpp>
#include <api/vao.hpp>
#include <api/vbo.hpp>

#include <util/vec.h>

using namespace api;

Vec3 vecs[4] = {
    vecCreateVec3(0.5f, 0.5f, 0.0f),
    vecCreateVec3(0.5f, -0.5f, 0.0f),
    vecCreateVec3(-0.5f, -0.5f, 0.0f),
    vecCreateVec3(-0.5f, 0.5f, 0.0f),
};
uint32 idx[6] = {
    0, 1, 2,
    3, 0, 2,
};

int32 main() {
    window::useCallouts(true);
    Window window(800, 600, "GL Test");
    
    shader::useCallouts(true);
    Shader shader;

    uint32 itt = 0;
    int64 startTime = gluGetMilliseconds();
    uint64 totalSecs = 0;
    
    vao::useCallouts(true);
    vbo::useCallouts(true);
    Vao vao;
    Vbo vbo(vecs, sizeof(vecs), vbo::type::VEC3);
    Vbo ebo(vbo::type::EBO, idx, sizeof(idx), 0);

    vao.bind();
    vbo.bind();
    vbo.vertexAttribPointer(0, 0);
    vao.unbind();
    vbo.unbind();

    bool typeLSchedule = false;
    bool wireframeEnabled = false;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    while (!window.shouldClose()) {
        itt++;

        window.focus();
        if (window.keyTyped(GLFW_KEY_L, typeLSchedule)) {
            if (wireframeEnabled) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                wireframeEnabled = false;
            }
            else {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                wireframeEnabled = true;
            }
        }

        glClearColor(0.33f, 0.66f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();
        vao.bind();
        ebo.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        shader.stopUse();
        vao.unbind();
        window.flush();
    }

    std::cout << "\nAverage loop time is " << (float64)(gluGetMilliseconds() - startTime) / (1000 * itt) << " seconds in " << itt << " itterations\n\n";

    return 0;
}