#ifndef VBO_HPP
#define VBO_HPP

// Local includes
#include <util/glutils.h>

namespace api {

namespace vbo {
    const int8 VBO = 0x1;
    const int8 EBO = 0x2;
    const int8 VEC2 = 0x3;
    const int8 VEC3 = 0x4;
    const int8 VEC4 = 0x5;
}
class Vbo {
public:
    Vbo(Vbo&) = delete;
    Vbo(void* vecs, uint64 size, int8 vecType, uint32 layoutNr);
    Vbo(int8 type, void* vecs, uint64 size, int8 vecType, uint32 layoutNr);
    ~Vbo();
private:
    void bufferData(int8 type, void* vecs, uint64 size, uint32 layoutNr, int8 elements, uint64 offset);
    uint32 address;
    int8 type;
};

}

#endif
