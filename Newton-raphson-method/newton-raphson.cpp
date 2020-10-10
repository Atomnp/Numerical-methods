#include <iostream>
#include<cmath>

class NewtonRaphson {
private:
	double* coefficient;
	int degree;
	double tolerance;
	int intervalLeft;
	int intervalRight;
	double abs(double a) {
		return a < 0 ? -1 * a : a;
	}
public:
	NewtonRaphson(double* coeff,int deg,double tol,int interl,int interR):
		coefficient(coeff),degree(deg),tolerance(tol),intervalLeft(interl),intervalRight(interR){}
	double f(double x) {
		double result = 0;
		for (int i = 0; i <= degree; i++) {
			result += coefficient[i] * std::pow(x, i);
		}
		return result;
	}
	double derivativeF(double x) {
		double result = 0;
		for (int i = 1; i <= degree; i++) {
			result += coefficient[i] *i* std::pow(x, i - 1);
		}
		return result;
	}
	double  solve() {
		for(int i=intervalLeft;i<=intervalRight;i++){
			int f1 = f(i);
			int f2 = f(i + 1);
			if (f1 * f2 < 0) {
				intervalLeft = f1 < f2 ? f1 : f2;
				intervalRight = f1 == intervalLeft ? f2 : f1;
				break;
			}
			if (i == intervalRight) {
				std::cout << " no solution exist in given interval" << std::endl;
				exit(0);
			}
		}
		double tempx = (intervalRight + intervalLeft) / 2.0;
		double newTemp;
		while (true) {
			newTemp = tempx - f( tempx) / derivativeF(tempx);
			if (abs(newTemp- tempx) < tolerance) {
				return newTemp;
			}
			tempx = newTemp;
		}
	}
};
int main() {
	std::cout << "Enter the degree of polynomial , left interval and right interval" << std::endl;
	int degree, intervalLeft, intervalRight;
	double tolerance;

	std::cin >> degree;
	std::cin >> intervalLeft;
	std::cin >> intervalRight;
	std::cout << "enter the tolerance " << std::endl;
	std::cin >> tolerance;

	double* coefficient = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++) {
		std::cout << "enter the coefficiont of" << i << std::endl;
		std::cin >> coefficient[i];
	}

	NewtonRaphson* solver = new NewtonRaphson(coefficient, degree, tolerance, intervalLeft, intervalRight);
	try {
		double result = solver->solve();
		std::cout << "the result is = " << result << std::endl;
	}
	catch (...) {
		std::cout << "no solution found" << std::endl;
	}
}
	