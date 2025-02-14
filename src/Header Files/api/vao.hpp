#ifndef VAO_HPP
#define VAO_HPP

// Local includes
#include <util/glutils.h>

namespace api {

namespace vao {

}
class Vao {
public:
    Vao(Vao&) = delete;
    Vao();
    ~Vao();
private:
    uint32 address;
};

}

#endif