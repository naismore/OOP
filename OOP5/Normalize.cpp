#include "Normalize.h"
CVector3D Normalize(CVector3D const& v) {
    double length = v.GetLength();
    if (length == 0) {
        throw std::invalid_argument("Cannot normalize a zero vector");
    }
    return CVector3D(v.x / length, v.y / length, v.z / length);
}