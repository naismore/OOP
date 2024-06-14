#include "CVector3D.h"
#include <limits>

// Конструирует нулевой вектор
CVector3D::CVector3D() : x(0), y(0), z(0) {}

// Конструирует вектор с заданными координатами
CVector3D::CVector3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0) {}

// Возвращает длину вектора
double CVector3D::GetLength() const {
    return sqrt(x * x + y * y + z * z);
}

// Нормализует вектор (приводит его к единичной длине)
void CVector3D::Normalize() {
    double length = GetLength();
    x /= length;
    y /= length;
    z /= length;
}

// Унарный минус
CVector3D CVector3D::operator-() const {
    return CVector3D(-x, -y, -z);
}

// Унарный плюс
CVector3D CVector3D::operator+() const {
    return *this;
}

// Бинарный плюс
CVector3D CVector3D::operator+(const CVector3D& other) const {
    return CVector3D(x + other.x, y + other.y, z + other.z);
}

// Бинарныйминус
CVector3D CVector3D::operator-(const CVector3D& other) const {
    return CVector3D(x - other.x, y - other.y, z - other.z);
}

// +=
CVector3D& CVector3D::operator+=(const CVector3D& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

// -=
CVector3D& CVector3D::operator-=(const CVector3D& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

// Умножение на скаляр
CVector3D CVector3D::operator*(double scalar) const {
    return CVector3D(x * scalar, y * scalar, z * scalar);
}

// Умножение скаляра на вектор
CVector3D operator*(double scalar, const CVector3D& vector) {
    return vector * scalar;
}

// Деление на скаляр
CVector3D CVector3D::operator/(double scalar) const {
    return CVector3D(x / scalar, y / scalar, z / scalar);
}

// *=
CVector3D& CVector3D::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

// /=
CVector3D& CVector3D::operator/=(double scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

// ==
bool CVector3D::operator==(const CVector3D& other) const {
    return fabs(x - other.x) < DBL_EPSILON &&
        fabs(y - other.y) < DBL_EPSILON &&
        fabs(z - other.z) < DBL_EPSILON;
}

//!=
bool CVector3D::operator!=(const CVector3D& other) const {
    return!(*this == other);
}

// Оператор вывода в выходной поток
std::ostream& operator<<(std::ostream& os, const CVector3D& vector) {
    os << vector.x << ", " << vector.y << ", " << vector.z;
    return os;
}

// Оператор ввода из входного потока
std::istream& operator>>(std::istream& is, CVector3D& vector) {
    is >> vector.x >> vector.y >> vector.z;
    return is;
}