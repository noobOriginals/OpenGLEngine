#include <api/vbo.hpp>
using namespace api::vbo;

// TODO: Finish callouts mesg

namespace api {

namespace vbo {
    uint32 vboCount = 0;
    bool callouts = false;
    uint32 getVboCount() { return vboCount; }
	void useCallouts(bool value) { callouts = value; }
}
Vbo::Vbo(void* vecs, uint64 size, int8 vecType, uint32 layoutNr) {
    // Set buffer type
    type = type::VBO;
    this->type = type;
    
    if (callouts) std::cout << "Creating " << (type == type::VBO ? "VBO" : "EBO") << " with nr. " << vboCount << "\n";

    // Create buffer
    glGenBuffers(1, &address);
    
    // Set buffer data
    bufferData(type, vecs, size, layoutNr, vecType, 0);
    
    // Unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    vboCount++;
}
Vbo::Vbo(int8 type, void* vecs, uint64 size, int8 vecType, uint32 layoutNr) {
    // Set buffer type
    if (type > type::EBO) type = type::VBO;
    this->type = type;
    
    if (callouts) std::cout << "Creating " << (type == type::VBO ? "VBO" : "EBO") << " with nr. " << vboCount << "\n";

    // Create buffer
    glGenBuffers(1, &address);
    
    // Set buffer data
    bufferData(type, vecs, size, layoutNr, vecType, 0);
    
    // Unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    vboCount++;
}
Vbo::~Vbo() {
    vboCount--;
    if (callouts) std::cout << "Destructing " << (type == type::VBO ? "VBO" : "EBO") << " with nr. " << vboCount << "\n";
    glDeleteBuffers(1, &address);
}
// Utility
void Vbo::bind() {
    if (type == type::VBO) {
        glBindBuffer(GL_ARRAY_BUFFER, address);
        return;
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, address);
}
void Vbo::unbind() {
    if (type == type::VBO) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        return;
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Private mehtods
void Vbo::bufferData(int8 type, void* vecs, uint64 size, uint32 layoutNr, int8 elements, uint64 offset) {
    if (type == type::VBO) {
        // Bind buffer
        glBindBuffer(GL_ARRAY_BUFFER, address);
        // Link pointers
        glBufferData(GL_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);

        // Tell OpenGL how to use the data
        glVertexAttribPointer(layoutNr, elements, GL_FLOAT, GL_FALSE, elements * sizeof(float32), (void*)offset);
        glEnableVertexAttribArray(layoutNr);

        return;
    }
    // Bind buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, address);
    // Link pointers
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);
}

}