#include <iostream>

#include <api/window.hpp>

using namespace api;

int main() {
    window::useCallouts(true);
    Window window(800, 600, "GL Test");

    while (!window.shouldClose()) {
        window.flush();
    }

    return 0;
}