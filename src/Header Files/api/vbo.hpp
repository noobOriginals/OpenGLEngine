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
    Vbo(void* vecs, uint64 size, int8 vecType, uint32 layoutNr);
    Vbo(int8 type, void* vecs, uint64 size, int8 vecType, uint32 layoutNr);
    ~Vbo();
    // Utility
    void bind();
    void unbind();

private:
    void bufferData(int8 type, void* vecs, uint64 size, uint32 layoutNr, int8 elements, uint64 offset);
    uint32 address;
    int8 type;
    void* vecs;
};

}

#endif
