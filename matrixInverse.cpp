#include "./headers/matrix.h"
#include <vector>
void rowOperation(std::vector<std::vector<Fraction>>& matrix, int i, int j) {
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
std::vector< std::vector<Fraction>>inverse(std::vector< std::vector<double>> matrix) {
	auto identity = matrix::identityMatrix(matrix.size());
	auto concatedMatrix=matrix::concatMatrix(matrix, identity);

	std::vector < std::vector<Fraction>>fractionMatrix(concatedMatrix.size());
	for (int j = 0; j < concatedMatrix.size(); j++) {
		for (int i = 0; i < concatedMatrix[0].size(); i++) {
			fractionMatrix[j].push_back(Fraction(concatedMatrix[j][i]));
		}
	}

	std::cout << "concated matrix" << std::endl;
	matrix::print2Darray(concatedMatrix);
	
	for (int j = 0; j < matrix[0].size(); j++) {
		for (int i = 0; i < matrix.size(); i++) {
			if (i != j and fractionMatrix[i][j].numerator != 0) {
				rowOperation(fractionMatrix, i, j);
				matrix::print2Darray(fractionMatrix);
			}
		}
	}
	for (int i = 0; i < fractionMatrix.size(); i++) {
		auto divider = fractionMatrix[i][i];
		for (int j = 0; j< fractionMatrix[0].size(); j++) {
			if (fractionMatrix[i][j].numerator != 0) {
				fractionMatrix[i][j] = fractionMatrix[i][j] / divider;
			}	
		}
	}
	
	std::cout << "final matrix" << std::endl;
	matrix::print2Darray(fractionMatrix);

	auto ans = matrix::getCols(fractionMatrix, matrix[0].size(), fractionMatrix[0].size()-1);
	return ans;
}
int main() {
	auto matrix = matrix::generateMatrix<double>(4, 4);
	auto inv = inverse(matrix);
	std::cout << "inverse is" << std::endl;
	matrix::print2Darray(inv);
	std::cout << "multiplying matrix and its inverse" << std::endl;
	auto fInv = matrix::fracMatToDoub(inv);
	auto res = matrix::matrixMul(matrix, fInv);
	matrix::print2Darray(res);
	
}