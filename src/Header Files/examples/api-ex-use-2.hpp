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

Point2D vecs[4] = {
    geoCreatePoint2D( 0.5f,  0.5f, 1.0f, 1.0f),
    geoCreatePoint2D( 0.5f, -0.5f, 1.0f, 0.0f),
    geoCreatePoint2D(-0.5f, -0.5f, 0.0f, 0.0f),
    geoCreatePoint2D(-0.5f,  0.5f, 0.0f, 1.0f),
};
uint32 idx[6] = {
    0, 1, 2,
    3, 0, 2,
};

int32 run() {
    Window window(800, 600, "Game");

    Shader sh(shader::loadSourceFromFile("vertShader.glsl"), shader::loadSourceFromFile("fragShader.glsl"));

    Texture tex("tex.png");

    Vao vao;
    Vbo vbo(vbo::type::VBO, vecs, sizeof(vecs), 4);
    Vbo ebo(vbo::type::EBO, idx, sizeof(idx), 0);

    vao.bind();
    vbo.bind();
    vbo.vertexAttribPointer(0, 0, vbo::type::VEC2);
    vbo.vertexAttribPointer(1, VEC_SIZEOF_VEC2, vbo::type::VEC2);
    vao.unbind();
    vbo.unbind();

    while (!window.shouldClose()) {
        window.focus();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        sh.use();
        sh.setInt("image", 0);
        sh.setFloatMat3("view", vecPtrMat3(vecLookAtMat3(vecCreateVec2(0.0f, 0.0f))));
        sh.setFloatMat3("projection", vecPtrMat3(vecProjectionMat3((float)800 / 600)));
        vao.bind();
        ebo.bind();
        glActiveTexture(GL_TEXTURE0);
        tex.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        vao.unbind();
        ebo.unbind();
        tex.unbind();

        window.flush();
    }

    return 0;
}