#ifndef CAMERA_HPP
#define CAMERA_HPP

// Std includes
#include <iostream>

// Local includes
#include <util/vec.h>

namespace api {

// 2D Camera API
namespace camera2D {
    uint32 getCameraCount();
	void useCallouts(bool callouts);
}
class Camera2D {
public:
    Camera2D(Camera2D&) = delete;
    Camera2D(Vec2 pos);
    ~Camera2D();
    // Utility
    Mat3 getViewMatrix();
    float32* getViewMatrixPtr();
    Vec2 getPos();
    void move(float32 mx, float32 my);
    void move(Vec2 dir, float32 speed);
    void moveX(float32 mx);
    void moveY(float32 my);
private:
    Vec2 pos;
    Mat3 transform;
};

// 3D Camera API
namespace camera3D {

}
class Camera3D {
public:
    Camera3D(Camera3D&) = delete;
    Camera3D(Vec3 pos, Vec3 target);
    ~Camera3D();
    // Utility
    Mat4 getViewMatrix();
    float32* getViewMatrixPtr();
    Vec3 getPos();
    Vec3 getTarget();
    Vec3 getCamUp();
private:
    Vec3 pos, target, up;
    Mat4 transform;
};

}

#endif