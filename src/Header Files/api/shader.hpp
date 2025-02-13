#ifndef SHADER_H
#define SHADER_H

// Std includes
#include <iostream>
#include <string>

// Lib includes
#include <glad/glad.h>
#include <glfw/glfw3.h>

// Local includes
#include <util/types.h>

namespace api {

// Shader API
namespace shader {

}
class Shader {
public:
    Shader();
    Shader(Shader&) = delete;
    Shader(const char* vsource, const char* fsource);
private:
    
};

}

#endif