#ifndef VEC_H
#define VEC_H

#define VEC_PI 3.14159265358979323846264338327950288

// Std includes
#include <stdio.h>
#include <math.h>

// Local includes
#include <util/types.h>

// Vecs
typedef struct Vec2 {
    float32 x, y;
} Vec2;
typedef struct Vec3 {
    float32 x, y, z;
} Vec3;
typedef struct Vec4 {
    float32 x, y, z, w;
} Vec4;
// Vector creation
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

// Matrices
typedef struct Mat2 {
    float32 e[2][2];
} Mat2;
typedef struct Mat3 {
    float32 e[3][3];
} Mat3;
typedef struct Mat4 {
    float32 e[4][4];
} Mat4;
// Matrix creation
Mat2 vecCreateMat2(float32 diag) {
    Mat2 mat;
    mat.e[0][0] = diag;
    mat.e[0][1] = 0.0f;
    mat.e[1][0] = 0.0f;
    mat.e[1][1] = diag;
    return mat;
}
Mat3 vecCreateMat3(float32 diag) {
    Mat3 mat;
    // First row
    mat.e[0][0] = diag;
    mat.e[0][1] = 0.0f;
    mat.e[0][2] = 0.0f;
    // Second row
    mat.e[1][0] = 0.0f;
    mat.e[1][1] = diag;
    mat.e[1][2] = 0.0f;
    // Thrid row
    mat.e[2][0] = 0.0f;
    mat.e[2][1] = 0.0f;
    mat.e[2][2] = diag;
    return mat;
}
Mat4 vecCreateMat4(float32 diag) {
    Mat4 mat;
    // First row
    mat.e[0][0] = diag;
    mat.e[0][1] = 0.0f;
    mat.e[0][2] = 0.0f;
    mat.e[0][3] = 0.0f;
    // Second row
    mat.e[1][0] = 0.0f;
    mat.e[1][1] = diag;
    mat.e[1][2] = 0.0f;
    mat.e[1][3] = 0.0f;
    // Thrid row
    mat.e[2][0] = 0.0f;
    mat.e[2][1] = 0.0f;
    mat.e[2][2] = diag;
    mat.e[2][3] = 0.0f;
    // Fourth row
    mat.e[3][0] = 0.0f;
    mat.e[3][1] = 0.0f;
    mat.e[3][2] = 0.0f;
    mat.e[3][3] = diag;
    return mat;
}

// Printing
void vecPrintVec2(Vec2 v) {
    printf("%f\n%f\n\n", v.x, v.y);
}
void vecPrintVec3(Vec3 v) {
    printf("%f\n%f\n%f\n\n", v.x, v.y, v.z);
}
void vecPrintVec4(Vec4 v) {
    printf("%f\n%f\n%f\n%f\n\n", v.x, v.y, v.z, v.w);
}
void vecPrintMat2(Mat2 m) {
    printf("%f %f\n", m.e[0][0], m.e[0][1]);
    printf("%f %f\n\n", m.e[1][0], m.e[1][1]);
}
void vecPrintMat3(Mat3 m) {
    printf("%f %f %f\n", m.e[0][0], m.e[0][1], m.e[0][2]);
    printf("%f %f %f\n", m.e[1][0], m.e[1][1], m.e[1][2]);
    printf("%f %f %f\n\n", m.e[2][0], m.e[2][1], m.e[2][2]);
}
void vecPrintMat4(Mat4 m) {
    printf("%f %f %f %f\n", m.e[0][0], m.e[0][1], m.e[0][2], m.e[0][3]);
    printf("%f %f %f %f\n", m.e[1][0], m.e[1][1], m.e[1][2], m.e[1][3]);
    printf("%f %f %f %f\n", m.e[2][0], m.e[2][1], m.e[2][2], m.e[2][3]);
    printf("%f %f %f %f\n\n", m.e[3][0], m.e[3][1], m.e[3][2], m.e[3][3]);
}
// Matrix creation methods
Mat2 vecRotationMat2(float64 angleInDeg) {
    float64 angle = angleInDeg * VEC_PI / 180.0f;
    float32 sinus = sin(angle);
    float32 cosinus = cos(angle);
    Mat2 m;
    // First row
    m.e[0][0] = cosinus;
    m.e[0][1] = -sinus;
    // Second row
    m.e[1][0] = sinus;
    m.e[1][1] = cosinus;
    return m;
}
Mat3 vecRotationMat3(float64 angleInDeg, float64 x, float64 y, float64 z) {
    float64 angle = angleInDeg * VEC_PI / 180.0f;
    float32 xsin = sin(angle * x);
    float32 ysin = sin(angle * y);
    float32 zsin = sin(angle * z);
    float32 xcos = cos(angle * x);
    float32 ycos = cos(angle * y);
    float32 zcos = cos(angle * z);
    Mat3 m;
    // First row
    m.e[0][0] = zcos * ycos;
    m.e[0][1] = zcos * ysin * xsin - zsin * xcos;
    m.e[0][2] = zcos * ysin * xcos + zsin * xsin;
    // Second row
    m.e[1][0] = zsin * ycos;
    m.e[1][1] = zsin * ysin * xsin + zcos * xcos;
    m.e[1][2] = zsin * ysin * xcos - zcos * xsin;
    // Thrid row
    m.e[2][0] = -ysin;
    m.e[2][1] = ycos * xsin;
    m.e[2][2] = ycos * xcos;
    return m;
}
// Transformations
// Cast
Vec2 vecCastVec3to2(Vec3 v) {
    Vec2 vec;
    vec.x = v.x;
    vec.y = v.y;
    return vec;
}
Vec2 vecCastVec4to2(Vec4 v) {
    Vec2 vec;
    vec.x = v.x;
    vec.y = v.y;
    return vec;
}
Vec3 vecCastVec2to3(Vec2 v, float32 z) {
    Vec3 vec;
    vec.x = v.x;
    vec.y = v.y;
    vec.z = z;
    return vec;
}
Vec3 vecCastVec4to3(Vec4 v) {
    Vec3 vec;
    vec.x = v.x;
    vec.y = v.y;
    vec.z = v.z;
    return vec;
}
Vec4 vecCastVec2to4(Vec2 v, float32 z, float32 w) {
    Vec4 vec;
    vec.x = v.x;
    vec.y = v.y;
    vec.z = z;
    vec.w = w;
    return vec;
}
Vec4 vecCastVec3to4(Vec3 v, float32 w) {
    Vec4 vec;
    vec.x = v.x;
    vec.y = v.y;
    vec.z = v.z;
    vec.w = w;
    return vec;
}
Mat2 vecCastMat3to2(Mat3 m) {
    Mat2 mat;
    // First row
    mat.e[0][0] = m.e[0][0];
    mat.e[0][1] = m.e[0][1];
    // Second row
    mat.e[1][0] = m.e[1][0];
    mat.e[1][1] = m.e[1][1];
    return mat;
}
Mat2 vecCastMat4to2(Mat4 m) {
    Mat2 mat;
    // First row
    mat.e[0][0] = m.e[0][0];
    mat.e[0][1] = m.e[0][1];
    // Second row
    mat.e[1][0] = m.e[1][0];
    mat.e[1][1] = m.e[1][1];
    return mat;
}
Mat3 vecCastMat2to3(Mat2 m, float32 diag) {
    Mat3 mat;
    // First row
    mat.e[0][0] = m.e[0][0];
    mat.e[0][1] = m.e[0][1];
    mat.e[0][2] = 0.0f;
    // Second row
    mat.e[1][0] = m.e[1][0];
    mat.e[1][1] = m.e[1][1];
    mat.e[1][2] = 0.0f;
    // Third row
    mat.e[2][0] = 0.0f;
    mat.e[2][1] = 0.0f;
    mat.e[2][2] = diag;
    return mat;
}
Mat3 vecCastMat4to3(Mat4 m) {
    Mat3 mat;
    // First row
    mat.e[0][0] = m.e[0][0];
    mat.e[0][1] = m.e[0][1];
    mat.e[0][2] = m.e[0][2];
    // Second row
    mat.e[1][0] = m.e[1][0];
    mat.e[1][1] = m.e[1][1];
    mat.e[1][2] = m.e[1][2];
    // Third row
    mat.e[2][0] = m.e[2][0];
    mat.e[2][1] = m.e[2][1];
    mat.e[2][2] = m.e[2][2];
    return mat;
}
Mat4 vecCastMat2to4(Mat2 m, float32 diag) {
    Mat4 mat;
    // First row
    mat.e[0][0] = m.e[0][0];
    mat.e[0][1] = m.e[0][1];
    mat.e[0][2] = 0.0f;
    mat.e[0][3] = 0.0f;
    // Second row
    mat.e[1][0] = m.e[1][0];
    mat.e[1][1] = m.e[1][1];
    mat.e[1][2] = 0.0f;
    mat.e[1][3] = 0.0f;
    // Third row
    mat.e[2][0] = 0.0f;
    mat.e[2][1] = 0.0f;
    mat.e[2][2] = diag;
    mat.e[2][3] = 0.0f;
    // Fourth row
    mat.e[3][0] = 0.0f;
    mat.e[3][1] = 0.0f;
    mat.e[3][2] = 0.0f;
    mat.e[3][3] = diag;
    return mat;
}
Mat4 vecCastMat3to4(Mat3 m, float32 diag) {
    Mat4 mat;
    // First row
    mat.e[0][0] = m.e[0][0];
    mat.e[0][1] = m.e[0][1];
    mat.e[0][2] = m.e[0][2];
    mat.e[0][3] = 0.0f;
    // Second row
    mat.e[1][0] = m.e[1][0];
    mat.e[1][1] = m.e[1][1];
    mat.e[1][2] = m.e[1][2];
    mat.e[1][3] = 0.0f;
    // Third row
    mat.e[2][0] = m.e[2][0];
    mat.e[2][1] = m.e[2][1];
    mat.e[2][2] = m.e[2][2];
    mat.e[2][3] = 0.0f;
    // Fourth row
    mat.e[3][0] = 0.0f;
    mat.e[3][1] = 0.0f;
    mat.e[3][2] = 0.0f;
    mat.e[3][3] = diag;
    return mat;
}
// Utility
float32 vecLengthVec2(Vec2 v) {
    float32 a = v.x * v.x;
    float32 b = v.y * v.y;
    return sqrt(a + b);
}
float32 vecLengthVec3(Vec3 v) {
    float32 a = v.x * v.x;
    float32 b = v.y * v.y;
    float32 c = v.z * v.z;
    return sqrt(a + b + c);
}
float32 vecLengthVec4(Vec4 v) {
    float32 a = v.x * v.x;
    float32 b = v.y * v.y;
    float32 c = v.z * v.z;
    float32 d = v.w * v.w;
    return sqrt(a + b + c + d);
}
// Inverse
Vec2 vecInverseVec2(Vec2 vec) {
    vec.x = -vec.x;
    vec.y = -vec.y;
    return vec;
}
Vec3 vecInverseVec3(Vec3 vec) {
    vec.x = -vec.x;
    vec.y = -vec.y;
    vec.z = -vec.z;
    return vec;
}
Vec4 vecInverseVec4(Vec4 vec) {
    vec.x = -vec.x;
    vec.y = -vec.y;
    vec.z = -vec.z;
    vec.w = -vec.w;
    return vec;
}
// Normalization
Vec2 vecNormalizeVec2(Vec2 v) {
    float32 length = vecLengthVec2(v);
    Vec2 vec;
    vec.x = v.x / length;
    vec.y = v.y / length;
    return vec;
}
Vec3 vecNormalizeVec3(Vec3 v) {
    float32 length = vecLengthVec3(v);
    Vec3 vec;
    vec.x = v.x / length;
    vec.y = v.y / length;
    vec.z = v.z / length;
    return vec;
}
Vec4 vecNormalizeVec4(Vec4 v) {
    float32 length = vecLengthVec4(v);
    Vec4 vec;
    vec.x = v.x / length;
    vec.y = v.y / length;
    vec.z = v.z / length;
    vec.w = v.w / length;
    return vec;
}
// Addition
Vec2 vecAddVec2(Vec2 v0, Vec2 v1) {
    Vec2 vec;
    vec.x = v0.x + v1.x;
    vec.y = v0.y + v1.y;
    return vec;
}
Vec3 vecAddVec3(Vec3 v0, Vec3 v1) {
    Vec3 vec;
    vec.x = v0.x + v1.x;
    vec.y = v0.y + v1.y;
    vec.z = v0.z + v1.z;
    return vec;
}
Vec4 vecAddVec4(Vec4 v0, Vec4 v1) {
    Vec4 vec;
    vec.x = v0.x + v1.x;
    vec.y = v0.y + v1.y;
    vec.z = v0.z + v1.z;
    vec.w = v0.w + v1.w;
    return vec;
}
// Invert fraction
Vec2 vecInvertVec2(Vec2 v) {
    Vec2 vec;
    vec.x = 1.0f / v.x;
    vec.y = 1.0f / v.y;
    return vec;
}
Vec3 vecInvertVec3(Vec3 v) {
    Vec3 vec;
    vec.x = 1.0f / v.x;
    vec.y = 1.0f / v.y;
    vec.z = 1.0f / v.z;
    return vec;
}
Vec4 vecInvertVec4(Vec4 v) {
    Vec4 vec;
    vec.x = 1.0f / v.x;
    vec.y = 1.0f / v.y;
    vec.z = 1.0f / v.z;
    vec.w = 1.0f / v.w;
    return vec;
}
// Multiplication
Vec2 vecMultiplyVec2(Vec2 v0, Vec2 v1) {
    Vec2 vec;
    vec.x = v0.x * v1.x;
    vec.y = v0.y * v1.y;
    return vec;
}
Vec3 vecMultiplyVec3(Vec3 v0, Vec3 v1) {
    Vec3 vec;
    vec.x = v0.x * v1.x;
    vec.y = v0.y * v1.y;
    vec.z = v0.z * v1.z;
    return vec;
}
Vec4 vecMultiplyVec4(Vec4 v0, Vec4 v1) {
    Vec4 vec;
    vec.x = v0.x * v1.x;
    vec.y = v0.y * v1.y;
    vec.z = v0.z * v1.z;
    vec.w = v0.w * v1.w;
    return vec;
}
// Dot product
float32 vecDotVec2(Vec2 v0, Vec2 v1) {
    float32 dot;
    dot = v0.x * v1.x + v0.y * v1.y;
    return dot;
}
float32 vecDotVec3(Vec3 v0, Vec3 v1) {
    float32 dot;
    dot = v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
    return dot;
}
float32 vecDotVec4(Vec4 v0, Vec4 v1) {
    float32 dot;
    dot = v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
    return dot;
}
// Cross product
Vec2 vecCrossVec2(Vec2 v0) {
    Vec2 vec;
    vec.x = v0.y;
    vec.y = -v0.x;
    return vec;
}
Vec3 vecCrossVec3(Vec3 v0, Vec3 v1) {
    Vec3 vec;
    vec.x = v0.y * v1.z - v0.z * v1.y;
    vec.y = v0.z * v1.x - v0.x * v1.z;
    vec.z = v0.x * v1.y - v0.y * v1.x;
    return vec;
}

#endif