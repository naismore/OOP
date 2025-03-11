#include "EquationSolver.h"
#include <cmath>

EquationRoot4 Solve4(double a, double b, double c, double d, double e) {
    if (a == 0) {
        throw std::invalid_argument("Коэффициент при x^4 не может быть равен нулю.");
    }

    // Преобразование коэффициентов для удобства
    double A = b / a;
    double B = c / a;
    double C = d / a;
    double D = e / a;

    // Используем метод Ferrari для нахождения корней
    // Сначала находим дискриминант
    double p = B - (A * A) / 4.0;
    double q = C + (A * A * A) / 8.0 - (A * B) / 2.0;
    double r = D - (A * A * A * A) / 256.0 + (A * A * B) / 16.0 - (A * C) / 4.0;

    // Решаем кубическое уравнение для нахождения корней
    std::array<double, 3> cubicRoots;
    int numCubicRoots = 0;

    // Используем формулу Кардано для решения кубического уравнения
    double discriminant = q * q / 4.0 + p * p * p / 27.0;

    if (discriminant < 0) {
        throw std::domain_error("Уравнение не имеет действительных корней.");
    } else if (discriminant == 0) {
        cubicRoots[numCubicRoots++] = -q / 2.0;
    } else {
        double u = std::cbrt(-q / 2.0 + std::sqrt(discriminant));
        double v = std::cbrt(-q / 2.0 - std::sqrt(discriminant));
        cubicRoots[numCubicRoots++] = u + v;
    }

    // Находим корни квадратного уравнения
    // Корни квадратного уравнения t^2 + pt + r = 0
    double discriminantQuadratic = cubicRoots[0] * cubicRoots[0] - 4 * r;

    if (discriminantQuadratic < 0) {
        throw std::domain_error("Уравнение не имеет действительных корней.");
    }

    EquationRoot4 result;

    if (numCubicRoots > 0) {
        result.roots[0] = cubicRoots[0] - sqrt(discriminantQuadratic) / 2;
        result.roots[1] = cubicRoots[0] + sqrt(discriminantQuadratic) / 2;
        result.numRoots = 2; // У нас два корня из квадратного уравнения
    } else {
        result.numRoots = 0; // Нет действительных корней
    }

    return result;
}