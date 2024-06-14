#include "CrossProduct.h"
CVector3D CrossProduct(const CVector3D& v1, const CVector3D& v2) {
    return CVector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}