#include <api/texture.hpp>
using namespace api::texture;

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

namespace api {

namespace texture {
    uint32 textureCount = 0;
    bool callouts = false;
    std::string def_texture = "";
    uint32 getTextureCount() { return textureCount; }
	void useCallouts(bool value) { callouts = value; }
    void setDefaultTexture(std::string filepath) { def_texture = filepath; }
}
Texture::Texture() {
    if (callouts) std::cout << "Texture: Loading texture from default filepath " << def_texture << "\n";
    this->filepath = def_texture;
    loadTexture(def_texture);
    textureCount++;
}
Texture::Texture(std::string filepath) {
    if (callouts) std::cout << "Texture: Loading texture from specified filepath " << filepath << "\n";
    this->filepath = filepath;
    loadTexture(filepath);
    textureCount++;
}
Texture::~Texture() {
    glDeleteTextures(1, &address);
    if (callouts) std::cout << "Destructing texture that was loaded from " << filepath << "\n";
    textureCount--;
}
// Utility
void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, address);
}
void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

// Private methods
void Texture::loadTexture(std::string filepath) {
    // Generarte and bind texture
    glGenTextures(1, &address);
    glBindTexture(GL_TEXTURE_2D, address);
    // Set texture params
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load texture
    stbi_set_flip_vertically_on_load(true);
    uint8* data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);
    if (!data) throw std::runtime_error("Failed to load texture from path " + filepath + "\n");
    int32 format = GL_RED;
    if (nrChannels == 3) format = GL_RGB;
    if (nrChannels == 4) format = GL_RGBA;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Discard unused resources
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

}