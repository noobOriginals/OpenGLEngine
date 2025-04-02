#ifndef VBO_HPP
#define VBO_HPP

// Std includes
#include <iostream>

// Local includes
#include <util/glutils.h>

namespace api {

namespace vbo {
    namespace type {
        const int8 VBO = 0x0;
        const int8 EBO = 0x1;
        const int8 VEC2 = 0x2;
        const int8 VEC3 = 0x3;
        const int8 VEC4 = 0x4;
    }

    uint32 getVboCount();
	void useCallouts(bool value);
}
class Vbo {
public:
    Vbo(Vbo&) = delete;
    Vbo(void* vecs, uint64 size);
    Vbo(int8 type, void* vecs, uint64 size);
    ~Vbo();
    // Utility
    void bind();
    void unbind();
    void vertexAttribPointer(uint32 layoutNr, uint64 offset, int8 vecType, int8 stride);
private:
    void bufferData(void* vecs, uint64 size);
    void vertexAttrib(uint32 layoutNr, uint8 elements, int8 stride, uint64 offset);
    uint32 address;
    int8 type;
};

}

#endif
