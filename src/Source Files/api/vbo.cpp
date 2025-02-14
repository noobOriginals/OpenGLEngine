#include <api/vbo.hpp>
using namespace api::vbo;

namespace api {

namespace vbo {
    
}
Vbo::Vbo(void* vecs, uint64 size, int8 vecType, uint32 layoutNr) {
    type = VBO;

    glGenBuffers(1, &address);
    glBindBuffer(GL_ARRAY_BUFFER, address);
}
Vbo::Vbo(int8 type, void* vecs, uint64 size, int8 vecType, uint32 layoutNr) {
    if (type > EBO) type = VBO;
    this->type = type;

    glGenBuffers(1, &address);
}

// Private mehtods
void Vbo::bufferData(int8 type, void* vecs, uint64 size, uint32 layoutNr, int8 elements, uint64 offset) {
    if (type == VBO) {
        glBindBuffer(GL_ARRAY_BUFFER, address);
        glBufferData(GL_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);

        glVertexAttribPointer(layoutNr, elements, GL_FLOAT, GL_FALSE, elements * sizeof(float32), (void*)offset);
        glEnableVertexAttribArray(layoutNr);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    else {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, address);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vecs, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

}