#ifndef CAMERA_HPP
#define CAMERA_HPP

// Std includes
#include <iostream>

// Local includes
#include <util/vec.h>

namespace api {

namespace camera {

}
class Camera {
public:
    Camera(Camera&) = delete;
    Camera(Vec3 pos, Vec3 dir);
    ~Camera();
private:
    Vec3 pos, dir;
    Mat4 transform;
};

}

#endif