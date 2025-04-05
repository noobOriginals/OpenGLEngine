#ifndef GEOMETRY_H
#define GEOMETRY_H

#ifdef __cplusplus
extern "C" {
#endif

// Local includes
#include <util/types.h>
#include <util/vec.h>

typedef struct Point2D {
    Vec2 point;
    Vec2 texCoords;
} Point2D;
typedef struct Point3D {
    Vec3 point;
    Vec2 texCoords;
} Point3D;

Point2D geoCreatePoint2D(float32 x, float32 y, float32 tx, float32 ty);
Point3D geoCreatePoint3D(float32 x, float32 y, float32 z, float32 tx, float32 ty);
Point2D geoCreatePoint2Dv(Vec2 pos, Vec2 tex);
Point3D geoCreatePoint3Dv(Vec3 pos, Vec2 tex);

#ifdef __cplusplus
}
#endif

#endif