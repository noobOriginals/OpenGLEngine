#ifndef OGLLIB_HPP
#define OGLLIB_HPP

// Std Includes
#include <iostream>
#include <string>

// API Includes
#include <api/window.hpp>
#include <api/shader.hpp>
#include <api/vao.hpp>
#include <api/vbo.hpp>
#include <api/texture.hpp>

// API Util Includes
#include <util/types.h>
#include <util/vec.h>
#include <util/geometry.h>

// Using 'api namespace for easier use'
using namespace api;

namespace ogllib {

class Window {
public:
    Window(int32 width, int32 height, std::string name);
private:

};

}

#endif