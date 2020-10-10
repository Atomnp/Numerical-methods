#pragma once

#include <vector>
#include<iostream>
#include <iomanip>
#include <time.h>
#include "fraction.h"

namespace matrix {
	template <typename T>
	using Matrix= std::vector<std::vector<T>>;

	template <typename T>
	std::vector<std::vector<T>>matrixMul(const std::vector<std::vector<T>>& m, const std::vector<std::vector<T>>& n) {
		if (m[0].size() != n.size()) {
			std::cout << "Provided  matrix cant be multiplied";
			exit(0);
		}
		std::vector<std::vector<T>>result(m.size());
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < n[0].size(); j++) {
				T  temp = 0;
				for (int k = 0; k < m[0].size(); k++) {
					temp = temp + m[i][k] * n[k][j];
				}
				result[i].push_back(temp);
			}
		}
		return result;
	}

	template <typename T>
	std::vector<std::vector<T>>generateMatrix(int row, int col) {
		
		std::vector<std::vector<T>>result(row);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				int randomNum = rand() % 20 - 10;
				T castedVal = (T)randomNum;
				result[i].push_back(randomNum);
			}
		}
		return result;
	}
	template <typename T>
	std::vector<std::vector<T>>concatMatrix(std::vector<std::vector<T>>m, std::vector<std::vector<T>>& n) {
		if (m.size() != n.size())
		{
			std::cout << "cannot concat matrix" << std::endl;
			exit(0);
		}

		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < n[0].size(); j++) {
				m[i].push_back(n[i][j]);
			}
		}
		return m;
	}
	template <typename T>
	void print2Darray(const std::vector<std::vector<T>>& matrix) {
		std::cout << "[\n";
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				std::cout << std::setw(15) << matrix[i][j] << " ,";
			}
			std::cout << "\n";
		}
		std::cout << "]";
	}

	std::vector<std::vector<double>>identityMatrix(int order) {
		std::vector<std::vector<double>>result(order);
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				i==j?result[i].push_back(1):result[i].push_back(0);
			}
		}
		return result;
	}

	template <typename T>
	std::vector<std::vector<T>>getCols(std::vector<std::vector<T>> matrix,int first,int second) {
		std::vector<std::vector<T>>result(matrix.size());
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = first; j <= second; j++) {
				result[i].push_back(matrix[i][j]);
			}
		}
		return result;
	}

	std::vector<std::vector<double>>fracMatToDoub(std::vector<std::vector<Fraction>>fracMatrix) {
		std::vector<std::vector<double>>res= std::vector<std::vector<double>>(fracMatrix.size());
		for (int i = 0; i < fracMatrix.size(); i++) {
			for (int j = 0; j < fracMatrix[0].size(); j++) {
				res[i].push_back(fracMatrix[i][j].toDecimal());
			}
		}
		return res;
	}
}
