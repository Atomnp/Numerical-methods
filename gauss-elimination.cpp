#include "./headers/matrix.h"

template <typename T>
void rowOperation(std::vector<std::vector<T>>& matrix, int i, int j) {
	//multiplier is determined based on which column we are operation 
	if (matrix[j][j] == 0) {
		std::cout << "Cannot perform division by zero... exiting computation" << std::endl;
		exit(0);
	}
	T multiplier = (matrix[i][j] / matrix[j][j]);
	matrix[i][j] = 0;
	for (int k = j+1; k < matrix[0].size(); k++) {
		matrix[i][k] = matrix[i][k] - multiplier * matrix[j][k];
	}
}
template <typename T>
std::vector<std::vector<T>> backSubstitution(std::vector<std::vector<T>>& matrix, int n) {
	std::vector<std::vector<T>>result(n);

	auto lastSoln = matrix[n - 1][n] / matrix[n - 1][n - 1];
	result[n - 1].push_back(lastSoln);


	//to implement final condition to get solution
	for (int i = n - 2; i >= 0; i--) {
		T temp = matrix[i][n];
		for (int j = result.size() - 1; j > i; j--) {
			temp =temp - matrix[i][j] * result[j][0];
		}
		T soln = temp / matrix[i][i];
		result[i].push_back(soln);
	}

	return result;
}

template <typename T>
std::vector<std::vector<T>>gaussElimination(std::vector<std::vector<T>>matrix) {
	int n = matrix.size();
	for (int j = 0; j < matrix[0].size() - 1; j++) {
		for (int i = j; i < n; i++) {
			if (i != j and matrix[i][j] != 0) {
				rowOperation(matrix, i, j);
				matrix::print2Darray(matrix);
			}
		}
	}
	//creating 2d array just to maintain it as a 2d matrix 1d vector of size n is being treated as
	//2d vector of row=n and col=1
	auto result = backSubstitution(matrix, n);
	return result;
}


int main() {
	srand(time(0));
	auto m = matrix::generateMatrix<Fraction>(4, 4);
	auto n = matrix::generateMatrix<Fraction>(4, 1);

	auto result = matrix::matrixMul<Fraction>(m, n);
	auto matrix = matrix::concatMatrix(m, result);

	std::cout << "Problem matrix" << std::endl;
	matrix::print2Darray(matrix);
	std::cout << "expected solution " << std::endl;
	matrix::print2Darray(n);

	auto solutions = gaussElimination(matrix);
	std::cout << "the solution is" << std::endl;
	matrix::print2Darray(solutions);
}