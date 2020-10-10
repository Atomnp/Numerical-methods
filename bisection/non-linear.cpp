#include <iostream>
#include <vector>
#include <iomanip>
struct Row {
	double a;
	double b;
	double c;
	Row(double a, double b, double c):a(a),b(b),c(c) {}
};

class NonLinearSolver {
private:
	double tolorenceError;
	double intervalFirst;
	double intervalSecond;
	std::vector<Row*>table;
	double abs(double input) {
		return input > 0 ? input : -1 * input;
	}
	double f(double x) {
		//hard coded function
		return x * x * x - 7;
	}

public:
	NonLinearSolver(double t,double f,double s):tolorenceError(t),intervalFirst(f),intervalSecond(s){}
	double solve() {
		double a = intervalFirst;
		double b = intervalSecond;

		double firstValue = f(a);
		double secondValue = f(b);

		double c;


		while (abs(a - b) >= tolorenceError) {
			c = (a + b) / 2;
			//for display purpose
			table.push_back(new Row(a, b, c));

			if (firstValue * f(c) < 0) {
				b = c;
			}
			else {
				a = c;
			}
		}
		return a;
	}

	void drawTable() {
		std::cout << "**********Iteration table********" << std::endl;
		std::cout << std::setw(20)<<std::left << "iteration";
		std::cout << std::setw(20)<<std::left << "a";
		std::cout << std::setw(20)<<std::left << "b";
		std::cout << std::setw(20)<<std::left << "c";
		std::cout << "\n--------------------------------------------------------------------------------------------" << std::endl;

		for (int i = 0; i < table.size();i++) {
			std::cout << std::setw(20)<<std::left << i + 1;
			std::cout << std::setw(20)<<std::left << table[i]->a;
			std::cout << std::setw(20)<<std::left << table[i]->b;
			std::cout << std::setw(20) << std::left << table[i]->c << std::endl;
		}
	}
};

int main() {
	double tolorenceError;
	double intervalFirst;
	double intervalSecond;
	std::cout << "input tolerance error" << std::endl;
	std::cin >> tolorenceError;
	std::cout << "input left interval" << std::endl;
	std::cin >> intervalFirst;
	std::cout << "input right interval" << std::endl;
	std::cin >>intervalSecond;

	NonLinearSolver solver(tolorenceError, intervalFirst, intervalSecond);
	double soln=solver.solve();
	solver.drawTable();
	std::cout << "\n the solution to given problem is" << soln;

}