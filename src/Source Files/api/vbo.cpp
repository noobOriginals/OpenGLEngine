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
Vbo::Vbo(void* vecs, uint64 size, int8 stride) {
    // Set buffer type
    type = type::VBO;
    this->type = type;

    if (callouts) std::cout << "Vbo: Creating " << (type == type::VBO ? "VBO" : "EBO") << " with nr. " << vboCount << "\n";

    this->stride = stride;

    // Create GL Buffer
    glGenBuffers(1, &address);
    // Link pointers to buffers
    bufferData(vecs, size);

    vboCount++;
}
Vbo::Vbo(int8 type, void* vecs, uint64 size, int8 stride) {
    // Set buffer type
    if (type > type::EBO) type = type::VBO;
    this->type = type;

    if (callouts) std::cout << "Vbo: Creating " << (type == type::VBO ? "VBO" : "EBO") << " with nr. " << vboCount << "\n";

    this->stride = stride;

    // Create GL Buffer
    glGenBuffers(1, &address);
    // Link pointers to buffers
    bufferData(vecs, size);

    vboCount++;
}
Vbo::~Vbo() {
    vboCount--;
    if (callouts) std::cout << "Vbo: Destructing " << (type == type::VBO ? "VBO" : "EBO") << " with nr. " << vboCount << "\n";
    if (vboCount < 1 && callouts) std::cout << "Vbo: No VBO's remaining\n";
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
void Vbo::vertexAttribPointer(uint32 layoutNr, uint64 offset, int8 vecType) {
    if (type == type::EBO) {
        if (callouts) std::cout << "Vbo: Trying to assign vertex attrib pointer to an EBO, which is not possible\n";
        return;
    }
    vertexAttrib(layoutNr, vecType, stride, offset);
}

// Private mehtods
void Vbo::bufferData(void* vecs, uint64 size) {
    if (type == type::VBO) {
        // Bind buffer
        glBindBuffer(GL_ARRAY_BUFFER, address);
        // Link pointers
        glBufferData(GL_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);
        // Unbind buffder
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        return;
    }
    // Bind buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, address);
    // Link pointers
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);
    // Unbind buffder
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void Vbo::vertexAttrib(uint32 layoutNr, uint8 elements, int8 stride, uint64 offset) {
    // Tell OpenGL how to use the data
    glVertexAttribPointer(layoutNr, elements, GL_FLOAT, GL_FALSE, stride * sizeof(float32), (void*)offset);
    glEnableVertexAttribArray(layoutNr);
}

}