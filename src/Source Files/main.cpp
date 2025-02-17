#include <iostream>

#include <api/window.hpp>
#include <api/shader.hpp>

#include <api/vao.hpp>

#include <util/vec.h>

using namespace api;

int32 main() {
    window::useCallouts(true);
    Window window(800, 600, "GL Test");
    
    shader::useCallouts(true);
    Shader shader;

    uint32 itt = 0;
    int64 startTime = gluGetMilliseconds();
    uint64 totalSecs = 0;
    

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

    uint32 address;
    uint32 ebo;

    vao::useCallouts(true);
    Vao vao;
    
    // Gen buffer
    glGenBuffers(1, &address);
    glGenBuffers(1, &ebo);
    // Bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, address);
    // Link pointers
    glBufferData(GL_ARRAY_BUFFER, sizeof(vecs), vecs, GL_STATIC_DRAW);
    // Tell OpenGL how to use the data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float32), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    // Bind buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    // Link pointers
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idx), idx, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    
    vao.bind();
    glBindBuffer(GL_ARRAY_BUFFER, address);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float32), (void*)0);
    glEnableVertexAttribArray(0);
    vao.unbind();
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    while (!window.shouldClose()) {
        itt++;

        window.focus();
        glClearColor(0.33f, 0.66f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        vao.bind();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        shader.stopUse();
        window.flush();
    }

    std::cout << "\nAverage loop time is " << (float64)(gluGetMilliseconds() - startTime) / (1000 * itt) << " seconds in " << itt << " itterations\n\n";

    return 0;
}