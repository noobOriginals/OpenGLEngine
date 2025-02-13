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
    // Set uniforms 1
    void setInt(int32 i, std::string name);
    void setUnsignedInt(uint32 ui, std::string name);
    void setFloat(float32 f, std::string name);
    void setDouble(float64 d, std::string name);
    // Set uniforms 2
    void setInt2(int32 i0, int32 i1, std::string name);
    void setUnsignedInt2(uint32 ui0, uint32 ui1, std::string name);
    void setFloat2(float32 f0, float32 f1, std::string name);
    void setDouble2(float64 d0, float64 d1, std::string name);
    // Set uniforms 3
    void setInt3(int32 i0, int32 i1, int32 i2, std::string name);
    void setUnsignedInt3(uint32 ui0, uint32 ui1, uint32 ui2, std::string name);
    void setFloat3(float32 f0, float32 f1, float32 f2, std::string name);
    void setDouble3(float64 d0, float64 d1, float64 d2, std::string name);
    // Set uniforms 4
    void setInt4(int32 i0, int32 i1, int32 i2, int32 i3, std::string name);
    void setUnsignedInt4(uint32 ui0, uint32 ui1, uint32 ui2, uint32 ui3, std::string name);
    void setFloat4(float32 f0, float32 f1, float32 f2, float32 f3, std::string name);
    void setDouble4(float64 d0, float64 d1, float64 d2, float64 d3, std::string name);
private:
    uint32 address = 0;
    void compileShaders(const char* vsource, const char* fsource);
};

}

#endif