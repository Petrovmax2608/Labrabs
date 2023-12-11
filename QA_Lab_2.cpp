#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>


double checker(double param)
{
    while (true)
    {
        try
        {
            if (!(std::cin >> param))
            {
                std::cin.clear();

                while (std::cin.get() != '\n');

                throw "Value is non digit!";
            }
            else
                break;
        }

        catch (const char* exception)
        {
            std::cout << exception << '\n';

            std::cout << "Type new agument value: ";
        }
    }
    return param;
}


std::complex<double> cubeRoot(std::complex<double> z)
{
    std::complex<double> i(0, 1);

    double r = std::abs(z);
    double phi = std::arg(z);

    return std::polar(std::cbrt(r), phi / 3);
}

std::vector<std::complex<double>> solution(double a, double b, double c, double d)

{
    b /= a;

    c /= a;

    d /= a;

    double q = (3.0 * c - pow(b, 2)) / 9.0;

    double r = (9.0 * b * c - 27.0 * d - 2.0 * pow(b, 3)) / 54.0;

    std::complex<double> Q(q, 0);
    std::complex<double> R(r, 0);

    std::complex<double> S = cubeRoot(R + sqrt(Q * Q * Q + R * R));

    std::complex<double> T = cubeRoot(R - sqrt(Q * Q * Q + R * R));

    std::complex<double> i(0, 1);
    std::complex<double> x1 = S + T - b / 3.0;
    std::complex<double> x2 = -(S + T) / 2.0 + i * (S - T) * sqrt(3.0) / 2.0 - b / 3.0;
    std::complex<double> x3 = -(S + T) / 2.0 - i * (S - T) * sqrt(3.0) / 2.0 - b / 3.0;

    std::vector<std::complex<double>> roots{x1, x2, x3};

    return roots;
}

void printComplex(const std::complex<double>& c)
{
    std::cout << c.real();
}

int main() {
    double a = 0, b = 0, c = 0, d = 0;

    std::cout << "Type arguments value: ";

    a = checker(a);

    b = checker(b);

    c = checker(c);

    d = checker(d);

    // Проверка на вырожденное уравнение (все коэффициенты = 0)
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        std::cout << "The equation has infinitely many solutions\n";
        return 0;
    }

    // Проверка на вырожденное уравнение (все коэффициенты, кроме свободного члена, = 0)
    if (a == 0 && b == 0 && c == 0 && d != 0) {
        std::cout << "The equation has no solutions\n";
        return 0;
    }

    // Проверка на линейное уравнение
    if (a == 0 && b == 0 && c != 0) {
        std::cout << "x = " << -d / c << "\n";
        return 0;
    }

    // Проверка на квадратное уравнение
    if (a == 0 && b != 0) {
        double D = c * c - 4 * b * d;
        if (D < 0) {
            std::cout << "The equation has no real solutions\n";
        }
        else if (D == 0) {
            std::cout << "x = " << -c / (2 * b) << "\n";
        }
        else {
            std::cout << "x1 = " << (-c + sqrt(D)) / (2 * b) << "\n";
            std::cout << "x2 = " << (-c - sqrt(D)) / (2 * b) << "\n";
        }
        return 0;
    }

    // Решение кубического уравнения
    auto roots = solution(a, b, c, d);

    for (int i = 1; i <= roots.size(); ++i)
    {
        std::cout << "x" << i << ": ";

        printComplex(roots[i - 1]);

        std::cout << "\n";
    }

    return 0;
}

