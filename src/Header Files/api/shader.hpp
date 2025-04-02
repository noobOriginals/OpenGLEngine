#ifndef SHADER_HPP
#define SHADER_HPP

// Std includes
#include <iostream>
#include <string>

// Local includes
#include <util/glutils.h>
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
    Shader(Shader&) = delete;
    Shader();
    Shader(std::string vsource, std::string fsource);
    ~Shader();
    // Utility
    void use();
    void stopUse();
    // Set uniforms 1
    void setInt(std::string name, int32 i);
    void setUnsignedInt(std::string name, uint32 ui);
    void setFloat(std::string name, float32 f);
    void setDouble(std::string name, float64 d);
    // Set uniforms 2
    void setInt2(std::string name, int32 i0, int32 i1);
    void setUnsignedInt2(std::string name, uint32 ui0, uint32 ui1);
    void setFloat2(std::string name, float32 f0, float32 f1);
    void setDouble2(std::string name, float64 d0, float64 d1);
    // Set uniforms 3
    void setInt3(std::string name, int32 i0, int32 i1, int32 i2);
    void setUnsignedInt3(std::string name, uint32 ui0, uint32 ui1, uint32 ui2);
    void setFloat3(std::string name, float32 f0, float32 f1, float32 f2);
    void setDouble3(std::string name, float64 d0, float64 d1, float64 d2);
    // Set uniforms 4
    void setInt4(std::string name, int32 i0, int32 i1, int32 i2, int32 i3);
    void setUnsignedInt4(std::string name, uint32 ui0, uint32 ui1, uint32 ui2, uint32 ui3);
    void setFloat4(std::string name, float32 f0, float32 f1, float32 f2, float32 f3);
    void setDouble4(std::string name, float64 d0, float64 d1, float64 d2, float64 d3);
private:
    void compileShaders(const char* vsource, const char* fsource);
    uint32 address;
};

}

#endif