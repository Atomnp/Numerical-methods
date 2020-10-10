#include <iostream>
#include <vector>

int lagrange(std::vector<int> x, std::vector<int> y, int at) {
	int size = x.size();
	
	float result = 0;
	for (int i = 0; i < size; i++) {
		int numerator = 1;
		int denominator = 1;
		for (int j = 0; j < size; j++) {
			if (j != i) {
				numerator *= (at - x[j]);
				denominator *= (x[i] - x[j]);
			}
		
		}
		float numFloat = numerator * 1.0;
		result += (numFloat / denominator)*y[i];
	}
	return result;
}

int main() {
	std::vector<int>x = {1,3,4,7,10};
	std::vector<int>y = {-1,21,56,329,980};
	int result = lagrange(x, y, 5);
}