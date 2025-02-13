#ifndef SHADER_HPP
#define SHADER_HPP

// Std includes
#include <iostream>
#include <string>

// Lib includes
#include <glad/glad.h>

// Local includes
#include <util/types.h>

namespace api {

// Shader API
namespace shader {
    uint32 getShaderCount();
	void useCallouts(bool callouts);
    std::string loadSourceFromFile(const char* filepath);
}
class Shader {
public:
    Shader();
    Shader(Shader&) = delete;
    Shader(std::string vsource, std::string fsource);
    ~Shader();
    // Utility
    void use();
private:
    uint32 address = 0;
    void compileShaders(const char* vsource, const char* fsource);
};

}

#endif