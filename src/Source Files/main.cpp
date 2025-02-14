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

    uint32 itt = 0;
    uint64 totalSecs = 0;

    int64 startTime = gluGetMilliseconds();

    while (!window.shouldClose() && !window1.shouldClose()) {
        itt++;

        window.focus();
        glClearColor(1.0f, 0.6f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        window.flush();

        window1.focus();
        glClearColor(0.3f, 0.6f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        window1.flush();
    }
    std::cout << "Average loop time is " << (float64)(gluGetMilliseconds() - startTime) / (1000 * itt) << " seconds\n";

    return 0;
}