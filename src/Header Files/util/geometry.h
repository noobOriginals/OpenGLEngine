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

Point2D geoCreatePoint2D(float32 x, float32 y, float32 tx, float32 ty) {
    Point2D p;
    p.point = vecCreateVec2(x, y);
    p.texCoords = vecCreateVec2(tx, ty);
    return p;
}
Point3D geoCreatePoint3D(float32 x, float32 y, float32 z, float32 tx, float32 ty) {
    Point3D p;
    p.point = vecCreateVec3(x, y, z);
    p.texCoords = vecCreateVec2(tx, ty);
    return p;
}
Point2D geoCreatePoint2Dv(Vec2 pos, Vec2 tex) {
    return geoCreatePoint2D(pos.x, pos.y, tex.x, tex.y);
}
Point3D geoCreatePoint3Dv(Vec3 pos, Vec2 tex) {
    return geoCreatePoint3D(pos.x, pos.y, pos.z, tex.x, tex.y);
}

#endif