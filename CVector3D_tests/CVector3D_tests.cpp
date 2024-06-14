#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../Vector3D/CVector3D.h"
#include "../Vector3D/DotProduct.h"
#include "../Vector3D/CrossProduct.h"
#include "../Vector3D/Normalize.h"

TEST_CASE("Конструкторы") {
    CVector3D v1; // конструктор по умолчанию
    REQUIRE(v1.x == 0);
    REQUIRE(v1.y == 0);
    REQUIRE(v1.z == 0);

    CVector3D v2(1, 2, 3); // конструктор с параметрами
    REQUIRE(v2.x == 1);
    REQUIRE(v2.y == 2);
    REQUIRE(v2.z == 3);
}

TEST_CASE("Унарный минус") {
    CVector3D v1(1, 2, 3);
    CVector3D v2 = -v1;
    REQUIRE(v2.x == -1);
    REQUIRE(v2.y == -2);
    REQUIRE(v2.z == -3);
}

TEST_CASE("Унарный плюс") {
    CVector3D v1(1, 2, 3);
    CVector3D v2 = +v1;
    REQUIRE(v2.x == 1);
    REQUIRE(v2.y == 2);
    REQUIRE(v2.z == 3);
}

TEST_CASE("Бинарный плюс") {
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D v3 = v1 + v2;
    REQUIRE(v3.x == 5);
    REQUIRE(v3.y == 7);
    REQUIRE(v3.z == 9);
}

TEST_CASE("Бинарный минус") {
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D v3 = v1 - v2;
    REQUIRE(v3.x == -3);
    REQUIRE(v3.y == -3);
    REQUIRE(v3.z == -3);
}

TEST_CASE("+= и -=") {
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);

    v1 += v2;
    REQUIRE(v1.x == 5);
    REQUIRE(v1.y == 7);
    REQUIRE(v1.z == 9);

    v1 -= v2;
    REQUIRE(v1.x == 1);
    REQUIRE(v1.y == 2);
    REQUIRE(v1.z == 3);
}

TEST_CASE("Умножение на скаляр") {
    CVector3D v1(1, 2, 3);
    CVector3D v2 = v1 * 2;
    REQUIRE(v2.x == 2);
    REQUIRE(v2.y == 4);
    REQUIRE(v2.z == 6);

    v2 = 2 * v1;
    REQUIRE(v2.x == 2);
    REQUIRE(v2.y == 4);
    REQUIRE(v2.z == 6);
}

TEST_CASE("Деление на скаляр") {
    CVector3D v1(2, 4, 6);
    CVector3D v2 = v1 / 2;
    REQUIRE(v2.x == 1);
    REQUIRE(v2.y == 2);
    REQUIRE(v2.z == 3);
}

TEST_CASE("*= и /=") {
    CVector3D v1(1, 2, 3);

    v1 *= 2;
    REQUIRE(v1.x == 2);
    REQUIRE(v1.y == 4);
    REQUIRE(v1.z == 6);

    v1 /= 2;
    REQUIRE(v1.x == 1);
    REQUIRE(v1.y == 2);
    REQUIRE(v1.z == 3);
}

TEST_CASE("== и !=") {
    CVector3D v1(1, 2, 3);
    CVector3D v2(1, 2, 3);
    REQUIRE(v1 == v2);
    REQUIRE(!(v1 != v2));

    CVector3D v3(4, 5, 6);
    REQUIRE(v1 != v3);
    REQUIRE(!(v1 == v3));
}

TEST_CASE("Оператор вывода") {
    CVector3D v1(1, 2, 3);
    std::stringstream ss;
    ss << v1;
    REQUIRE(ss.str() == "1, 2, 3");
}

TEST_CASE("Оператор ввода") {
    std::stringstream ss("1 2 3");
    CVector3D v1;
    ss >> v1;
    REQUIRE(v1.x == 1);
    REQUIRE(v1.y == 2);
    REQUIRE(v1.z == 3);
}

TEST_CASE("DotProduct") {
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    REQUIRE(DotProduct(v1, v2) == Approx(32.0));
}

TEST_CASE("CrossProduct") {
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D result = CrossProduct(v1, v2);
    REQUIRE(result.x == Approx(-3.0));
    REQUIRE(result.y == Approx(6.0));
    REQUIRE(result.z == Approx(-3.0));
}

TEST_CASE("Normalize") {
    CVector3D v(3, 4, 0);
    CVector3D normalized = Normalize(v);
    REQUIRE(normalized.GetLength() == Approx(1.0));
    REQUIRE(normalized.x == Approx(3.0 / 5.0));
    REQUIRE(normalized.y == Approx(4.0 / 5.0));
    REQUIRE(normalized.z == Approx(0.0));
}