#include "./headers/matrix.h"

void rowOperation(std::vector<std::vector<Fraction>>&matrix, int i, int j) {
	//multiplier is determined based on which column we are operation 
	if (matrix[j][j].numerator == 0) {
		std::cout << "Cannot perform division by zero... exiting computation" << std::endl;
		exit(0);
	}
	Fraction multiplier = (matrix[i][j] / matrix[j][j]);
	
	for (int k = j; k < matrix[0].size(); k++) {
		matrix[i][k] = matrix[i][k] - multiplier * matrix[j][k];
	}
}

std::vector<std::vector<Fraction>>solve(std::vector<std::vector<double>>matrix) {
	std::vector < std::vector<Fraction>>fractionMatrix(matrix.size());
	for (int j = 0; j < matrix.size(); j++) {
		for (int i = 0; i < matrix[0].size(); i++) {
			fractionMatrix[j].push_back(Fraction(matrix[j][i]));
		}
	}
	for (int j = 0; j < matrix[0].size()-1; j++) {
		for (int i = 0; i<matrix.size(); i++) {
			if (i != j and matrix[i][j]!=0) {
				rowOperation(fractionMatrix, i, j);
				matrix::print2Darray(fractionMatrix);
			}
		}
	}
	std::vector<std::vector<Fraction>>result(matrix.size());
	for (int n = 0; n < fractionMatrix.size();n++) {
		result[n].push_back( fractionMatrix[n][fractionMatrix.size()]/ fractionMatrix[n][n] );
	}
	return result;
}


int main() {
	auto m = matrix::generateMatrix(4, 4);
	auto n = matrix::generateMatrix(4, 1);

	auto result = matrix::matrixMul(m, n);
	auto matrix = matrix::concatMatrix(m, result);
	std::cout << "Problem matrix" << std::endl;
	matrix::print2Darray(matrix);
	std::cout << "expected solution " << std::endl;
	matrix::print2Darray(n);

	auto solutions = solve(matrix);
	std::cout << "the solution is" << std::endl;
	matrix::print2Darray(solutions);


}