#pragma once
#include <iostream>

class CVector3D
{
public:
    CVector3D();

    CVector3D(double x0, double y0, double z0);

    double GetLength() const;
    void Normalize();

    CVector3D operator-() const;
    CVector3D operator+() const;

    CVector3D operator+(CVector3D &other) const;
    CVector3D operator-(CVector3D &other) const;

    friend std::ostream& operator<<(std::ostream &os, const CVector3D &vec);

    double x, y, z;
};