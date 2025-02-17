#ifndef VAO_HPP
#define VAO_HPP

// Std includes
#include <iostream>

// Local includes
#include <util/glutils.h>

namespace api {

namespace vao {
    uint32 getVaoCount();
	void useCallouts(bool value);
}
class Vao {
public:
    Vao(Vao&) = delete;
    Vao();
    ~Vao();
    /// Utility
    void bind();
    void unbind();
private:
    uint32 address;
};

}

#endif