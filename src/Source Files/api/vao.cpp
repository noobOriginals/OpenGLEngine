#include <api/vao.hpp>
using namespace api::vao;

namespace api {

namespace vao {
    uint32 vaoCount = 0;
    bool callouts = false;
    uint32 getVaoCount() { return vaoCount; }
	void useCallouts(bool value) { callouts = value; }
}
Vao::Vao() {
    if (callouts) std::cout << "Creating VAO with nr. " << vaoCount << "\n";
    glGenVertexArrays(1, &address);
    vaoCount++;
}
Vao::~Vao() {
    vaoCount--;
    if (callouts) std::cout << "Destructing VAO with nr. " << vaoCount << "\n";
    glDeleteVertexArrays(1, &address);
}
/// Utility
void Vao::bind() {
    glBindVertexArray(address);
}
void Vao::unbind() {
    glBindVertexArray(0);
}

}