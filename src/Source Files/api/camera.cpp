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

    camera2D::cameraCount++;
}
Camera2D::~Camera2D() {
    camera2D::cameraCount--;
}
// Utility
Mat3 Camera2D::getViewMatrix() {
    transform = vecLookAtMat3(pos);
    return transform;
}
Vec2 Camera2D::getPos() {
    return pos;
}
void Camera2D::move(float32 mx, float32 my) {
    pos = vecAddVec2(pos, vecCreateVec2(mx, my));
}
void Camera2D::move(Vec2 dir, float32 speed) {
    dir = vecNormalizeVec2(dir);
    pos = vecAddVec2(pos, vecCreateVec2(dir.x * speed, dir.y * speed));
}
void Camera2D::moveX(float32 mx) {
    pos = vecAddVec2(pos, vecCreateVec2(mx, 0.0f));
}
void Camera2D::moveY(float32 my) {
    pos = vecAddVec2(pos, vecCreateVec2(0.0f, my));
}

// 3D Camera
namespace camera3D {
    uint32 cameraCount = 0;
    bool callouts = false;
	uint32 getCameraCount() { return cameraCount; }
	void useCallouts(bool value) { callouts = value; }
}
Camera3D::Camera3D(Vec3 pos, Vec3 target) {
    this->pos = pos;
    this->target = target;
    up = vecCreateVec3(0.0f, 1.0f, 0.0f);

    camera3D::cameraCount++;
}
Camera3D::~Camera3D() {
    camera3D::cameraCount--;
}
// Utility
Mat4 Camera3D::getViewMatrix() {
    transform = vecLookAtMat4(pos, target, up);
    return transform;
}
Vec3 Camera3D::getPos() {
    return pos;
}
Vec3 Camera3D::getTarget() {
    return target;
}
Vec3 Camera3D::getCamUp() {
    return up;
}
void Camera3D::move(float32 mx, float32 my, float32 mz) {
    pos = vecAddVec3(pos, vecCreateVec3(mx, my, mz));
    target = vecAddVec3(target, vecCreateVec3(mx, my, mz));
}
void Camera3D::move(Vec3 dir, float32 speed) {
    dir = vecNormalizeVec3(dir);
    pos = vecAddVec3(pos, vecCreateVec3(dir.x * speed, dir.y * speed, dir.z * speed));
    target = vecAddVec3(target, vecCreateVec3(dir.x * speed, dir.y * speed, dir.z * speed));
}
void Camera3D::moveX(float32 mx) {
    pos = vecAddVec3(pos, vecCreateVec3(mx, 0.0f, 0.0f));
    target = vecAddVec3(target, vecCreateVec3(mx, 0.0f, 0.0f));
}
void Camera3D::moveY(float32 my) {
    pos = vecAddVec3(pos, vecCreateVec3(0.0f, my, 0.0f));
    target = vecAddVec3(target, vecCreateVec3(0.0f, my, 0.0f));
}
void Camera3D::moveZ(float32 mz) {
    pos = vecAddVec3(pos, vecCreateVec3(0.0f, 0.0f, mz));
    target = vecAddVec3(target, vecCreateVec3(0.0f, 0.0f, mz));
}
void Camera3D::setTarget(Vec3 target) {
    this->target = target;
}
void Camera3D::rotate(float32 angX, float32 angY) {
    Mat3 rot = vecRotationMat3(1.0f, angX, angY, 0.0f);
    target = vecDotMV3(rot, vecAddVec3(target, vecInverseVec3(pos)));
    target = vecAddVec3(target, pos);
}

}