#include <util/vec.h>

// Std includes
#include <stdio.h>
#include <math.h>

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

// Ptr
float32* vecPtrMat2(Mat2 m) {
    float32* ptr = (float32*)m.e;
    return ptr;
}
float32* vecPtrMat3(Mat3 m) {
    float32* ptr = (float32*)m.e;
    return ptr;
}
float32* vecPtrMat4(Mat4 m) {
    float32* ptr = (float32*)m.e;
    return ptr;
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
    if (length == 0) return v;
    Vec2 vec;
    vec.x = v.x / length;
    vec.y = v.y / length;
    return vec;
}
Vec3 vecNormalizeVec3(Vec3 v) {
    float32 length = vecLengthVec3(v);
    if (length == 0) return v;
    Vec3 vec;
    vec.x = v.x / length;
    vec.y = v.y / length;
    vec.z = v.z / length;
    return vec;
}
Vec4 vecNormalizeVec4(Vec4 v) {
    float32 length = vecLengthVec4(v);
    if (length == 0) return v;
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

// Matrix multiplication
Vec2 vecDotMV2(Mat2 m, Vec2 v) {
    Vec2 vec;
    vec.x = m.e[0][0] * v.x + m.e[0][1] * v.y;
    vec.y = m.e[1][0] * v.x + m.e[1][1] * v.y;
    return vec;
}
Vec3 vecDotMV3(Mat3 m, Vec3 v) {
    Vec3 vec;
    vec.x = m.e[0][0] * v.x + m.e[0][1] * v.y + m.e[0][2] * v.z;
    vec.y = m.e[1][0] * v.x + m.e[1][1] * v.y + m.e[1][2] * v.z;
    vec.z = m.e[2][0] * v.x + m.e[2][1] * v.y + m.e[2][2] * v.z;
    return vec;
}
Vec4 vecDomMV4(Mat3 m, Vec4 v) {
    Vec4 vec;
    vec.x = m.e[0][0] * v.x + m.e[0][1] * v.y + m.e[0][2] * v.z + m.e[0][3] * v.w;
    vec.y = m.e[1][0] * v.x + m.e[1][1] * v.y + m.e[1][2] * v.z + m.e[1][3] * v.w;
    vec.z = m.e[2][0] * v.x + m.e[2][1] * v.y + m.e[2][2] * v.z + m.e[2][3] * v.w;
    vec.w = m.e[3][0] * v.x + m.e[3][1] * v.y + m.e[3][2] * v.z + m.e[3][3] * v.w;
    return vec;
}
Mat2 vecDotMat2(Mat2 m0, Mat2 m1) {
    Mat2 m;
    int32 r, c;
    // First row
    r = 0; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c];
    r = 0; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c];
    // Second row
    r = 1; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c];
    r = 1; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c];
    return m;
}
Mat3 vecDotMat3(Mat3 m0, Mat3 m1) {
    Mat3 m;
    int32 r, c;
    // First row
    r = 0; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    r = 0; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    r = 0; c = 2; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    // Second row
    r = 1; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    r = 1; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    r = 1; c = 2; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    // Third row
    r = 2; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    r = 2; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    r = 2; c = 2; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c];
    return m;
}
Mat4 vecDotMat4(Mat4 m0, Mat4 m1) {
    Mat4 m;
    int32 r, c;
    // First row
    r = 0; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 0; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 0; c = 2; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 0; c = 3; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    // Second row
    r = 1; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 1; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 1; c = 2; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 1; c = 3; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    // Third row
    r = 2; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 2; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 2; c = 2; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 2; c = 3; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    // Fourth row
    r = 3; c = 0; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 3; c = 1; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 3; c = 2; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    r = 3; c = 3; m.e[r][c] = m0.e[r][0] * m1.e[0][c] + m0.e[r][1] * m1.e[1][c] + m0.e[r][2] * m1.e[2][c] + m0.e[r][3] * m1.e[3][c];
    return m;
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
Mat4 vecRotaionMat4(float64 angleInDeg, float64 x, float64 y, float64 z) {
    float64 angle = angleInDeg * VEC_PI / 180.0f;
    float32 xsin = sin(angle * x);
    float32 ysin = sin(angle * y);
    float32 zsin = sin(angle * z);
    float32 xcos = cos(angle * x);
    float32 ycos = cos(angle * y);
    float32 zcos = cos(angle * z);
    Mat4 m = vecCreateMat4(1.0f);
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
Mat2 vecScaleMat2(float32 sx, float32 sy) {
    Mat2 m = vecCreateMat2(sx);
    m.e[1][1] = sy;
    return m;
}
Mat3 vecScaleMat3(float32 sx, float32 sy, float32 sz) {
    Mat3 m = vecCreateMat3(sx);
    m.e[1][1] = sy;
    m.e[2][2] = sz;
    return m;
}
Mat4 vecScaleMat4(float32 sx, float32 sy, float32 sz) {
    Mat4 m = vecCreateMat4(1.0f);
    m.e[0][0] = sx;
    m.e[1][1] = sy;
    m.e[2][2] = sz;
    return m;
}
Mat3 vecTranslationMat3(float32 tx, float32 ty) {
    Mat3 m = vecCreateMat3(1.0f);
    m.e[0][2] = tx;
    m.e[1][2] = ty;
    return m;
}
Mat4 vecTranslationMat4(float32 tx, float32 ty, float32 tz) {
    Mat4 m = vecCreateMat4(1.0f);
    m.e[0][3] = tx;
    m.e[1][3] = ty;
    m.e[2][3] = tz;
    return m;
}
Mat3 vecLookAtMat3(Vec2 pos) {
    Mat3 m = vecCreateMat3(1.0f);
    m.e[0][2] = -pos.x;
    m.e[1][2] = -pos.y;
    return m;
}
Mat3 vecProjectionMat3(float32 aspectRatio) {
    Mat3 m = vecCreateMat3(1.0f);
    if (aspectRatio > 1.0f) m.e[0][0] = 1.0f / aspectRatio;
    if (aspectRatio < 1.0f) m.e[1][1] = aspectRatio;
    return m;
}
Mat4 vecLookAtMat4(Vec3 pos, Vec3 target, Vec3 up) {
    Vec3 dir = vecAddVec3(pos, vecInverseVec3(target));
    Vec3 right = vecCrossVec3(up, dir);
    Mat4 l = vecCreateMat4(1.0f);
    Mat4 r = vecTranslationMat4(-pos.x, -pos.y, -pos.z);
    // Right vec
    l.e[0][0] = right.x;
    l.e[0][1] = right.y;
    l.e[0][2] = right.z;
    // Up vec
    l.e[1][0] = up.x;
    l.e[1][1] = up.y;
    l.e[1][2] = up.z;
    // Dir vec
    l.e[2][0] = dir.x;
    l.e[2][1] = dir.y;
    l.e[2][2] = dir.z;
    return vecDotMat4(l, r);
}
Mat4 vecOrthoMat4(float32 left, float32 right, float32 bottom, float32 top, float32 near, float32 far) {
    Mat4 m = vecCreateMat4(1.0f);
    m.e[0][0] = 2 / (right - left);
    m.e[0][3] = -(right + left) / (right - left);
    m.e[1][1] = 2 / (top - bottom);
    m.e[1][3] = -(top + bottom) / (top - bottom);
    m.e[2][2] = -2 / (far - near);
    m.e[2][3] = -(far + near) / (far - near);
    return m;
}
Mat4 vecPerspectiveMat4() {
    return vecCreateMat4(1.0f);
}