#include "Normalize.h"

CVector3D Normalize(const CVector3D& v)
{
    double length = v.GetLength();
    return CVector3D(v.x / length, v.y / length, v.z / length);
}
