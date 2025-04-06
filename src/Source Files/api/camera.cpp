#include <api/camera.hpp>
using namespace api::camera2D;
using namespace api::camera3D;

namespace api {

// 2D Camera
namespace camera2D {
    uint32 cameraCount = 0;
    bool callouts = false;
	uint32 getCameraCount() { return cameraCount; }
	void useCallouts(bool value) { callouts = value; }
}
Camera2D::Camera2D(Vec2 pos) {
    this->pos = pos;
    transform = vecLookAtMat3(pos);
}
// Utility
Mat3 Camera2D::getViewMatrix() {
    return transform;
}
float32* Camera2D::getViewMatrixPtr() {
    return vecPtrMat3(transform);
}
Vec2 Camera2D::getPos() {
    return pos;
}
void Camera2D::move(float32 mx, float32 my) {
    pos = vecAddVec2(pos, vecCreateVec2(mx, my));
    transform = vecLookAtMat3(pos);
}
void Camera2D::move(Vec2 dir, float32 speed) {
    dir = vecNormalizeVec2(dir);
    pos = vecAddVec2(pos, vecCreateVec2(dir.x * speed, dir.y * speed));
    transform = vecLookAtMat3(pos);
}
void Camera2D::moveX(float32 mx) {
    pos = vecAddVec2(pos, vecCreateVec2(mx, 0.0f));
    transform = vecLookAtMat3(pos);
}
void Camera2D::moveY(float32 my) {
    pos = vecAddVec2(pos, vecCreateVec2(0.0f, my));
    transform = vecLookAtMat3(pos);
}

// 3D Camera
namespace camera3D {
    uint32 cameraCount = 0;
    bool callouts = false;
	uint32 getCameraCount() { return cameraCount; }
	void useCallouts(bool value) { callouts = value; }
}

}