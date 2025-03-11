#define BOOST_TEST_MODULE EquationSolverTests
#include <boost/test/included/unit_test.hpp>
#include "EquationSolver.h" // Include your header file

BOOST_AUTO_TEST_CASE(test_Solve4_ValidRoots) {
    EquationRoot4 result = Solve4(1, -10, 35, -50, 24); // Example coefficients
    BOOST_TEST(result.numRoots == 4);
    BOOST_TEST(result.roots[0] == 2);
    BOOST_TEST(result.roots[1] == 3);
    BOOST_TEST(result.roots[2] == 4);
    BOOST_TEST(result.roots[3] == 1);
}

BOOST_AUTO_TEST_CASE(test_Solve4_NoRealRoots) {
    BOOST_CHECK_THROW(Solve4(1, 0, 1, 0, 1), std::domain_error); // x^4 + x^2 + 1 = 0 has no real roots
}

BOOST_AUTO_TEST_CASE(test_Solve4_InvalidCoefficient) {
    BOOST_CHECK_THROW(Solve4(0, 1, 2, 3, 4), std::invalid_argument); // Coefficient of x^4 cannot be zero
}

BOOST_AUTO_TEST_CASE(test_Solve4_OneRoot) {
    EquationRoot4 result = Solve4(1, -6, 11, -6, 0); // Example coefficients for (x-1)(x-2)(x-3) = 0
    BOOST_TEST(result.numRoots == 3);
    BOOST_TEST(result.roots[0] == 1);
    BOOST_TEST(result.roots[1] == 2);
    BOOST_TEST(result.roots[2] == 3);
}

// 13 Типы данных вещественных чисел
// 11 Контейнеры unordered map и 
// 4 Перегрузка арифметических операций и опрераций сравнения