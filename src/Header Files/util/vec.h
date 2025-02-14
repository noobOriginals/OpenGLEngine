#ifndef VEC_H
#define VEC_H

// Std includes
#include <stdlib.h>

// Local includes
#include <util/types.h>

typedef struct Vec2 {
    float32 x, y;
    const int8 numElements = 2;
} Vec2;
typedef struct Vec3 {
    float32 x, y, z;
    const int8 numElements = 3;
} Vec3;
typedef struct Vec4 {
    float32 x, y, z, w;
    const int8 numElements = 4;
} Vec4;

Vec2 vecCreateVec2(float32 x, float32 y) {
    Vec2 vec;
    vec.x = x;
    vec.y = y;
    return vec;
}
Vec3 vecCreateVec3(float32 x, float32 y, float32 z) {
    Vec3 vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}
Vec4 vecCreateVec4(float32 x, float32 y, float32 z, float32 w) {
    Vec4 vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;
    return vec;
}
#endif