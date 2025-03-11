#include "DotProduct.h"
double DotProduct(CVector3D const& v1, CVector3D const& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}