#include "./headers/matrix.h"

template <typename T>
std::vector<std::vector<T>> backSubstitution(const std::vector<std::vector<T>>& matrix, int n) {
	std::vector<std::vector<T>>result(n);

	auto lastSoln = matrix[n - 1][n] / matrix[n - 1][n - 1];
	result[n - 1].push_back(lastSoln);
	for (int i = n - 2; i >= 0; i--) {
		T temp = matrix[i][n];
		for (int j = result.size() - 1; j > i; j--) {
			temp =temp- matrix[i][j] * result[j][0];
		}
		T soln = temp / matrix[i][i];
		result[i].push_back(soln);
	}

	return result;
}
template <typename T>
std::vector<std::vector<T>> forwardSubstitution(const std::vector<std::vector<T>>& matrix, int n) {
	std::vector<std::vector<T>>result(n);

	auto firstSoln = matrix[0][n] ;
	result[0].push_back(firstSoln);

	for (int i = 1; i <= n-1; i++) {
		T temp = matrix[i][n];
		for (int j =0; j < i; j++) {
			temp =temp- matrix[i][j] * result[j][0];
		}
		result[i].push_back(temp);
	}

	return result;
}

template <typename T>
void Factorize(matrix::Matrix<T>& matrix, matrix::Matrix<T>& L, matrix::Matrix<T>& U) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (i <= j) {
				T temp = matrix[i][j];
				for (int k = 0; k <= i - 1; k++) {
					temp = temp - L[i][k] * U[k][j];
				}
				U[i][j] = temp;
				L[i][j] = i == j ?  1 : 0;
			}
			else {
				T temp = matrix[i][j];
				for (int k = 0; k <= j - 1; k++) {
					temp = temp - L[i][k] * U[k][j];
				}
				L[i][j] = temp/U[j][j];
				 U[i][j] = 0 ;
			}
		}
	}
}
int main() {
	srand(time(0));
	auto matrix = matrix::generateMatrix<Fraction>(4, 4);
	auto soln = matrix::generateMatrix<Fraction>(4, 1);
	auto qn = matrix::matrixMul(matrix, soln);
	auto concatedMatrix = matrix::concatMatrix(matrix, qn);
	std::cout << "augmented Probllem matrix of size"<<concatedMatrix.size()<<"X" << concatedMatrix.size() << std::endl;
	matrix::print2Darray(concatedMatrix);
	std::cout << "the expected soln is" << std::endl;
	matrix::print2Darray(soln);

	auto L = matrix::generateMatrix<Fraction>(4, 4);
	auto U = matrix::generateMatrix<Fraction>(4, 4);

	Factorize(matrix, L, U);
	std::cout << "L and U" << std::endl;
	matrix::print2Darray(L);
	matrix::print2Darray(U);

	std::cout << "-------------------------------------" << std::endl;

	auto firstAns = forwardSubstitution(matrix::concatMatrix(L,qn),L.size());
	auto secondAns = backSubstitution(matrix::concatMatrix(U, firstAns),U.size());
	std::cout << "After first (foreward ) substitution" << std::endl;
	matrix::print2Darray(firstAns);
	std::cout << "After second (backward ) substitution" << std::endl;
	matrix::print2Darray(secondAns);
}