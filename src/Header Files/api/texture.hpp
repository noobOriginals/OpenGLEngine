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
    uint32 getTextureCount();
	void useCallouts(bool callouts);
    void setDefaultTexture(std::string filepath);
}
class Texture {
public:
    Texture();
    Texture(std::string filepath);
    ~Texture();
private:
    void loadTexture(std::string filepath);
    uint32 address;
    int32 width, height, nrChannels;
    std::string filepath;
};

}

#endif