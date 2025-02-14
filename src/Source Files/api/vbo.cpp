#include <api/vbo.hpp>
using namespace api::vbo;

// TODO: Finish callouts mesg

namespace api {

namespace vbo {
    uint32 vboCount = 0;
    bool callouts = false;
    uint32 getTextureCount() { return vboCount; }
	void useCallouts(bool value) { callouts = value; }
}
Vbo::Vbo(void* vecs, uint64 size, int8 vecType, uint32 layoutNr) {
    // Set buffer type
    type = VBO;
    this->type = type;

    bufferData(type, vecs, size, layoutNr, vecType - 1, 0);

    vboCount++;
}
Vbo::Vbo(int8 type, void* vecs, uint64 size, int8 vecType, uint32 layoutNr) {
    // Set buffer type
    if (type > EBO) type = VBO;
    this->type = type;

    bufferData(type, vecs, size, layoutNr, vecType - 1, 0);

    vboCount++;
}
Vbo::~Vbo() {
    vboCount--;
    if (callouts) std::cout << "\n";
    glDeleteBuffers(1, &address);
}
void Vbo::bind() {
    if (type == VBO) {
        glBindBuffer(GL_ARRAY_BUFFER, address);
        return;
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, address);
}
void Vbo::unbind() {
    if (type == VBO) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        return;
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Private mehtods
void Vbo::bufferData(int8 type, void* vecs, uint64 size, uint32 layoutNr, int8 elements, uint64 offset) {
    if (type == VBO) {
        // Bind buffer
        glBindBuffer(GL_ARRAY_BUFFER, address);
        // Link pointers
        glBufferData(GL_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);

        // Tell OpenGL how to use the data
        glVertexAttribPointer(layoutNr, elements, GL_FLOAT, GL_FALSE, elements * sizeof(float32), (void*)offset);
        glEnableVertexAttribArray(layoutNr);

        // Unbind buffer
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        return;
    }
    // Bind buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, address);
    // Link pointers
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);
    
    // Unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

}