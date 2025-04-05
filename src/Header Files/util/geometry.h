#ifndef GEOMETRY_H
#define GEOMETRY_H

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

Point2D geo_geoCreatePoint2D(float32 x, float32 y, float32 tx, float32 ty);
Point3D geo_geoCreatePoint3D(float32 x, float32 y, float32 z, float32 tx, float32 ty);
Point2D geo_geoCreatePoint2Dv(Vec2 pos, Vec2 tex);
Point3D geo_geoCreatePoint3Dv(Vec3 pos, Vec2 tex);

#define geoCreatePoint2D geo_geoCreatePoint2D
#define geoCreatePoint3D geo_geoCreatePoint3D
#define geoCreatePoint2Dv geo_geoCreatePoint2Dv
#define geoCreatePoint3Dv geo_geoCreatePoint3Dv

#endif