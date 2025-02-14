#include <iostream>

#include <api/window.hpp>
#include <api/shader.hpp>

using namespace api;

int32 main() {
    Window window(800, 600, "GL Test");
    
    shader::useCallouts(true);
    Shader shader;

    while (!window.shouldClose()) {
        window.flush();
    }

    return 0;
}