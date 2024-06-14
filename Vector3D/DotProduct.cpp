#include "DotProduct.h"

double DotProduct(const CVector3D& v1, const CVector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
