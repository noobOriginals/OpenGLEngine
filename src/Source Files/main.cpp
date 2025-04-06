#include <examples/api-ex-use.hpp>
#include <glm/gtc/type_ptr.hpp>

int32 main() {
    Vec3 pos = vecCreateVec3(0.5f, 0.5f, 1.0f);
    Mat3 view = vecLookAtMat3(vecCreateVec2(-0.2f, 0.0f));
    vecPrintVec3(pos);
    vecPrintMat3(view);
    pos = vecDotMV3(view, pos);
    vecPrintVec3(pos);
    vecPrintMat3(view);

    glm::mat3 m(1.0f);
    m[0][2] = 1.0f;
    for (int32 i = 0; i < 3; i++) {
        for (int32 j = 0; j < 3; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    glm::value_ptr(m);


    return run();
}