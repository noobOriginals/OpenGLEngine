#include <iostream>

#include <api/window.hpp>
// #include <api/shader.hpp>

using namespace api;

int32 main() {
    window::useCallouts(true);

    Window window(800, 600, "GL Test");
    Window window1(800, 600, "GL Test 1");
    
    // shader::useCallouts(true);
    // Shader shader;

    while (!window.shouldClose() && !window1.shouldClose()) {
        window.focus();
        glClearColor(1.0f, 0.6f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        window.flush();

        window1.focus();
        glClearColor(0.3f, 0.6f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        window1.flush();
    }

    return 0;
}