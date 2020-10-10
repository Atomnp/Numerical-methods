#include <iostream>
#include <math.h>
double f(int, double*, double);
double rootFinder(double, double, double, double);
double derivf(int, double*, double);




int main() {
    std::cout << "Enter the degree of polynomial";
    int degree;
    std::cin >> degree;
    double a = 0, b = 0, e, x0 = 0;
    std::cout << "Enter the tolerance";
    std::cin >> e;
    std::cout << "Enter the coefficient in a0, a1 ,a2,a3 format";
    double* coef = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        std::cin >> coef[i];

    }
    while (f(degree, coef, a) * f(degree, coef, b) > 0); {
        std::cout << "Re/Enter the interval limits";
        std::cin >> a;
        std::cin >> b;
        x0 = (a + b) / 2;
    }

    std::cout << "The root is" << rootFinder(f(degree, coef, x0), derivf(degree, coef, x0), x0, e);
    delete[] coef;
    return 0;
}

double f(int degree, double* coef, double x0) {
    double value = 0;
    for (int i = 0; i < degree + 1; i++) {
        value = value + coef[i] * pow(x0, i);
    }
    return value;
}

double derivf(int degree, double* coef, double x0) {
    double value = 0;
    for (int i = 1; i < degree + 1; i++) {
        value += i * coef[i] * pow(x0, i - 1);
    }
    return value;
}

double rootFinder(double f, double df, double x0, double e) {
    while (f >= e) {
        x0 = x0 - (f / df);
    }
    return x0;
}