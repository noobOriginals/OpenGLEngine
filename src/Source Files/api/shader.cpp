#include <api/shader.hpp>
using namespace api::shader;

// Std includes
#include <fstream>

const char* def_vsource =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;\n"
"void main() {\n"
"    gl_Position = vec4(pos, 1.0);\n"
"}";
const char* def_fsource =
"#version 330 core\n"
"out vec4 color;\n"
"void main() {\n"
"    color = vec4(1.0, 0.66, 0.33, 1.0);\n"
"}\n";

namespace api {

namespace shader {
    uint32 shaderCount = 0;
    bool callouts = false;
	uint32 getShaderCount() { return shaderCount; }
	void useCallouts(bool value) { callouts = value; }
    std::string loadSourceFromFile(const char* filepath) {
        std::fstream file(filepath, std::ios::in);
        std::string source = "";
        std::string line;
        while (getline(file, line)) source += line + "\n";
        return source;
    }
}
Shader::Shader() {
    if (!gluIsGLFWInitialized()) throw std::runtime_error("No windows were created, so GLAD is probably not initialized.");

    if (callouts) std::cout << "Shader: Creating shader nr. " << shaderCount << " with default sources.\n";
    compileShaders(def_vsource, def_fsource);
    shaderCount = shaderCount + 1;
}
Shader::Shader(std::string vsource, std::string fsource) {
    if (!gluIsGLFWInitialized()) throw std::runtime_error("No windows were created, so GLAD is probably not initialized.");

    if (callouts) std::cout << "Shader: Creating shader nr. " << shaderCount << " with custom sources.\n";
    compileShaders(vsource.c_str(), fsource.c_str());
    shaderCount++;
}
Shader::~Shader() {
    glDeleteProgram(address);
    shaderCount = shaderCount - 1;
    if (callouts) std::cout << "Shader: Destructing shader nr. " << shaderCount << "\n";
    if (shaderCount < 1 && callouts) std::cout << "Shader: No shaders remaining\n";
}
// Utility
void Shader::use() {
    glUseProgram(address);
}
void Shader::stopUse() {
    glUseProgram(0);
}
// Set uniforms 1
void Shader::setInt(std::string name, int32 i) {
    glUniform1i(glGetUniformLocation(address, name.c_str()), i);
}
void Shader::setUnsignedInt(std::string name, uint32 ui) {
    glUniform1ui(glGetUniformLocation(address, name.c_str()), ui);
}
void Shader::setFloat(std::string name, float32 f) {
    glUniform1f(glGetUniformLocation(address, name.c_str()), f);
}
void Shader::setDouble(std::string name, float64 d) {
    glUniform1d(glGetUniformLocation(address, name.c_str()), d);
}
// Set uniforms 2
void Shader::setInt2(std::string name, int32 i0, int32 i1) {
    glUniform2i(glGetUniformLocation(address, name.c_str()), i0, i1);
}
void Shader::setUnsignedInt2(std::string name, uint32 ui0, uint32 ui1) {
    glUniform2ui(glGetUniformLocation(address, name.c_str()), ui0, ui1);
}
void Shader::setFloat2(std::string name, float32 f0, float32 f1) {
    glUniform2f(glGetUniformLocation(address, name.c_str()), f0, f1);
}
void Shader::setDouble2(std::string name, float64 d0, float64 d1) {
    glUniform2d(glGetUniformLocation(address, name.c_str()), d0, d1);
}
// Set uniforms 3
void Shader::setInt3(std::string name, int32 i0, int32 i1, int32 i2) {
    glUniform3i(glGetUniformLocation(address, name.c_str()), i0, i1, i2);
}
void Shader::setUnsignedInt3(std::string name, uint32 ui0, uint32 ui1, uint32 ui2) {
    glUniform3ui(glGetUniformLocation(address, name.c_str()), ui0, ui1, ui2);
}
void Shader::setFloat3(std::string name, float32 f0, float32 f1, float32 f2) {
    glUniform3f(glGetUniformLocation(address, name.c_str()), f0, f1, f2);
}
void Shader::setDouble3(std::string name, float64 d0, float64 d1, float64 d2) {
    glUniform3d(glGetUniformLocation(address, name.c_str()), d0, d1, d2);
}
// Set uniforms 4
void Shader::setInt4(std::string name, int32 i0, int32 i1, int32 i2, int32 i3) {
    glUniform4i(glGetUniformLocation(address, name.c_str()), i0, i1, i2, i3);
}
void Shader::setUnsignedInt4(std::string name, uint32 ui0, uint32 ui1, uint32 ui2, uint32 ui3) {
    glUniform4ui(glGetUniformLocation(address, name.c_str()), ui0, ui1, ui2, ui3);
}
void Shader::setFloat4(std::string name, float32 f0, float32 f1, float32 f2, float32 f3) {
    glUniform4f(glGetUniformLocation(address, name.c_str()), f0, f1, f2, f3);
}
void Shader::setDouble4(std::string name, float64 d0, float64 d1, float64 d2, float64 d3) {
    glUniform4d(glGetUniformLocation(address, name.c_str()), d0, d1, d2, d3);
}

// Private methods
void Shader::compileShaders(const char* vsource, const char* fsource) {
    if (callouts) std::cout << "Shader: Compiling shaders...\n";
    // Catch errors
    int32 success;
    char infoLog[512];

    // Compile vertex shader
    uint32 vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, 1, &vsource, nullptr);
    glCompileShader(vshader);
    // Check for compilation errors
    glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vshader, 512, nullptr, infoLog);
        std::cout << "Shader: Failed to compile vertex shader:\n" << infoLog << "\n";
    }
    if (callouts) std::cout << "Shader: Successfully compiled vertex shader\n";

    // Compile fragment shader
    uint32 fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, 1, &fsource, nullptr);
    glCompileShader(fshader);
    // Check for compilation errors
    glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fshader, 512, nullptr, infoLog);
        std::cout << "Shader: Failed to compile fragment shader:\n" << infoLog << "\n";
    }
    if (callouts) std::cout << "Shader: Successfully compiled fragment shader\n";

    // Create program
    address = glCreateProgram();

    glAttachShader(address, vshader);
    glAttachShader(address, fshader);
    glLinkProgram(address);
    // Check for compilation errors
    glGetProgramiv(address, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(address, 512, nullptr, infoLog);
        std::cout << "Shader: Failed to link shaders:\n" << infoLog << "\n";
    }
    if (callouts) std::cout << "Shader: Successfully linked shader\n";

    // Discard unused reources
    glDeleteShader(vshader);
    glDeleteShader(fshader);
}

}