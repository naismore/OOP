#ifndef CVECTOR3D_H
#define CVECTOR3D_H

#include <iostream>
#include <cmath>

class CVector3D
{
public:
    // Конструирует нулевой вектор
    CVector3D();

    // Конструирует вектор с заданными координатами
    CVector3D(double x0, double y0, double z0);

    // Возвращает длину вектора
    double GetLength() const;

    // Нормализует вектор (приводит его к единичной длине)
    void Normalize();

    // Унарный минус
    CVector3D operator-() const;

    // Унарный плюс
    CVector3D operator+() const;

    // Бинарный плюс
    CVector3D operator+(const CVector3D& other) const;

    // Бинарный минус
    CVector3D operator-(const CVector3D& other) const;

    // +=
    CVector3D& operator+=(const CVector3D& other);

    // -=
    CVector3D& operator-=(const CVector3D& other);

    // Умножение на скаляр
    CVector3D operator*(double scalar) const;

    // Умножение скаляра на вектор
    friend CVector3D operator*(double scalar, const CVector3D& vector);

    // Деление на скаляр
    CVector3D operator/(double scalar) const;

    // *=
    CVector3D& operator*=(double scalar);

    // /=
    CVector3D& operator/=(double scalar);

    // ==
    bool operator==(const CVector3D& other) const;

    //!=
    bool operator!=(const CVector3D& other) const;

    // Оператор вывода в выходной поток
    friend std::ostream& operator<<(std::ostream& os, const CVector3D& vector);

    // Оператор ввода из входного потока
    friend std::istream& operator>>(std::istream& is, CVector3D& vector);

    double x, y, z;
};

#endif // CVECTOR3D_H