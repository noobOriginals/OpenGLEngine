#ifndef VEC_H
#define VEC_H

#ifdef __cplusplus
extern "C" {
#endif

#define VEC_PI 3.14159265358979323846264338327950288
#define VEC_SIZEOF_VEC2 8
#define VEC_SIZEOF_VEC3 12
#define VEC_SIZEOF_VEC4 16
#define VEC_SIZEOF_MAT2 16
#define VEC_SIZEOF_MAT3 36
#define VEC_SIZEOF_MAT4 64

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

// Vector creation
Vec2 vecCreateVec2(float32 x, float32 y);
Vec3 vecCreateVec3(float32 x, float32 y, float32 z);
Vec4 vecCreateVec4(float32 x, float32 y, float32 z, float32 w);

// Matrix creation
Mat2 vecCreateMat2(float32 diag);
Mat3 vecCreateMat3(float32 diag);
Mat4 vecCreateMat4(float32 diag);

// Printing
void vecPrintVec2(Vec2 v);
void vecPrintVec3(Vec3 v);
void vecPrintVec4(Vec4 v);
void vecPrintMat2(Mat2 m);
void vecPrintMat3(Mat3 m);
void vecPrintMat4(Mat4 m);

// Transformations
// Cast
Vec2 vecCastVec3to2(Vec3 v);
Vec2 vecCastVec4to2(Vec4 v);
Vec3 vecCastVec2to3(Vec2 v, float32 z);
Vec3 vecCastVec4to3(Vec4 v);
Vec4 vecCastVec2to4(Vec2 v, float32 z, float32 w);
Vec4 vecCastVec3to4(Vec3 v, float32 w);
Mat2 vecCastMat3to2(Mat3 m);
Mat2 vecCastMat4to2(Mat4 m);
Mat3 vecCastMat2to3(Mat2 m, float32 diag);
Mat3 vecCastMat4to3(Mat4 m);
Mat4 vecCastMat2to4(Mat2 m, float32 diag);
Mat4 vecCastMat3to4(Mat3 m, float32 diag);
// Utility
float32 vecLengthVec2(Vec2 v);
float32 vecLengthVec3(Vec3 v);
float32 vecLengthVec4(Vec4 v);
// Inverse
Vec2 vecInverseVec2(Vec2 vec);
Vec3 vecInverseVec3(Vec3 vec);
Vec4 vecInverseVec4(Vec4 vec);
// Normalization
Vec2 vecNormalizeVec2(Vec2 v);
Vec3 vecNormalizeVec3(Vec3 v);
Vec4 vecNormalizeVec4(Vec4 v);
// Addition
Vec2 vecAddVec2(Vec2 v0, Vec2 v1);
Vec3 vecAddVec3(Vec3 v0, Vec3 v1);
Vec4 vecAddVec4(Vec4 v0, Vec4 v1);
// Invert fraction
Vec2 vecInvertVec2(Vec2 v);
Vec3 vecInvertVec3(Vec3 v);
Vec4 vecInvertVec4(Vec4 v);
// Multiplication
Vec2 vecMultiplyVec2(Vec2 v0, Vec2 v1);
Vec3 vecMultiplyVec3(Vec3 v0, Vec3 v1);
Vec4 vecMultiplyVec4(Vec4 v0, Vec4 v1);
// Dot product
float32 vecDotVec2(Vec2 v0, Vec2 v1);
float32 vecDotVec3(Vec3 v0, Vec3 v1);
float32 vecDotVec4(Vec4 v0, Vec4 v1);
// Cross product
Vec2 vecCrossVec2(Vec2 v0);
Vec3 vecCrossVec3(Vec3 v0, Vec3 v1);

// Matrix multiplication
Vec2 vecDotMV2(Mat2 m, Vec2 v);
Vec3 vecDotMV3(Mat3 m, Vec3 v);
Vec4 vecDomMV4(Mat3 m, Vec4 v);
Mat2 vecDotMat2(Mat2 m0, Mat2 m1);
Mat3 vecDotMat3(Mat3 m0, Mat3 m1);
Mat4 vecDotMat4(Mat4 m0, Mat4 m1);

// Matrix creation methods
Mat2 vecRotationMat2(float64 angleInDeg);
Mat3 vecRotationMat3(float64 angleInDeg, float64 x, float64 y, float64 z);
Mat4 vecRotaionMat4(float64 angleInDeg, float64 x, float64 y, float64 z);
Mat2 vecScaleMat2(float32 sx, float32 sy);
Mat3 vecScaleMat3(float32 sx, float32 sy, float32 sz);
Mat4 vecScaleMat4(float32 sx, float32 sy, float32 sz);
Mat3 vecTranslationMat3(float32 tx, float32 ty);
Mat4 vecTranslationMat4(float32 tx, float32 ty, float32 tz);
Mat4 vecLookAtMat4(Vec3 pos, Vec3 target, Vec3 up);
Mat4 vecOrthoMat4();

#ifdef __cplusplus
}
#endif

#endif