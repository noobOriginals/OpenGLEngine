#ifndef TEXTURE_HPP
#define TEXTURE_HPP

// Std includes
#include <iostream>
#include <string>

// Local includes
#include <util/glutils.h>

namespace api {

// Texture API
namespace texture {

}
class Texture {
public:
    Texture();
    Texture(std::string filepath);
private:
    uint64 address;
};

}

#endif