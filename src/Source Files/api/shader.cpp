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
"    color = vec4(1.0, 0.5, 0.1, 1.0);\n"
"}\n";

bool isGLFWInitialized() {
    glfwGetKeyScancode(0);
    return glfwGetError(nullptr) != GLFW_NOT_INITIALIZED;
}

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
    if (!isGLFWInitialized()) throw std::runtime_error("No windows were created, so GLAD is probably not initialized.");
    
    if (callouts) std::cout << "Shader: Creating shader nr. " << shaderCount << " with default sources.\n";
    compileShaders(def_vsource, def_fsource);
    shaderCount = shaderCount + 1;
}
Shader::Shader(std::string vsource, std::string fsource) {
    if (!isGLFWInitialized()) throw std::runtime_error("No windows were created, so GLAD is probably not initialized.");
    
    if (callouts) std::cout << "Shader: Creating shader nr. " << shaderCount << " with custom sources.\n";
    compileShaders(vsource.c_str(), fsource.c_str());
    shaderCount++;
}
Shader::~Shader() {
    glDeleteProgram(address);
    shaderCount = shaderCount - 1;
    if (callouts) std::cout << "Shader: Destroying shader nr. " << shaderCount << "\n";
    if (shaderCount < 1 && callouts) std::cout << "Shader: No shaders remaining\n";
}
// Utility
void Shader::use() {
    glUseProgram(address);
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