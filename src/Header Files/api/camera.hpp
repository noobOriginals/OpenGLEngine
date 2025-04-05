#ifndef CAMERA_HPP
#define CAMERA_HPP

// Std includes
#include <iostream>

// Local includes
#include <util/vec.h>

namespace api {

namespace camera2D {

}
class Camera2D {
public:
    Camera2D(Camera3D&) = delete;
    Camera2D(Vec3 pos, Vec3 dir);
    ~Camera2D();
private:
    Vec2 pos;
};

namespace camera3D {

}
class Camera3D {
public:
    Camera3D(Camera3D&) = delete;
    Camera3D(Vec3 pos, Vec3 dir);
    ~Camera3D();
private:
    Vec3 pos, dir;
    Mat4 transform;
};

}

#endif