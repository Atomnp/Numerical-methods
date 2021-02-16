#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "../../../headers/matrix.h"

//equation used is of the form y=a+bx

void printData(std::string filename)
{
    std::ifstream fin(filename);
    std::string input;
    std::cout << "data set is shown below" << std::endl;
    while (getline(fin, input))
    {
        std::cout << input << std::endl;
    }
}
double sum_product(const std::vector<double> &x, const std::vector<double> &y)
{
    //we assume that vector x and y are of equal size
    double sum = 0;
    for (int i = 0; i < x.size(); i++)
    {
        sum += x[i] * y[i];
    }
    return sum;
}
std::vector<double> solve_gauss_jordan(std::vector<std::vector<double>> matrix)
{
    //here matrix m is the augmented matrix now i need to solve this matrix and return result
    //in vector
    unsigned n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0.0005)
        {
            std::cout << "The matrix is in ill condition" << std::endl;
        }
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            double ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++)
            {
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }
        }
    }
    std::vector<double> soln;
    for (int i = 0; i < n; i++)
    {
        soln.push_back(matrix[i][n] / matrix[i][i]);
    }
    return soln;
}

int main()
{
    std::string filename = "./input.txt";
    printData(filename);
    std::ifstream fin(filename);
    std::vector<double> x_values;
    std::vector<double> y_values;
    double sum_x = 0;
    double sum_y = 0;
    unsigned int data_size = 0;
    double a, b;
    while (fin >> a >> b)
    {
        x_values.push_back(a);
        //all calculation related to the y should be done with natural log of y
        //this result came by modifing the equation y=ae^bx==>log(y)=log(a)+bx;
        y_values.push_back(log(b));
        sum_x += a;
        sum_y += log(b);
        data_size++;
    }
    //now i have the create the matrirx and solve the equation using gauss elimination
    //we need to solve this augmented matrix to get the value of a and b
    //where
    //Y=A+bx is the desired linear curve where Y=log(y) and A=log(a)
    /*
    ** n        sum(x)    :sum(Y)
    ** sum(x)   sum(x^2)  :sum(xY)
    */
    auto matrix = matrix::generateMatrix<double>(2, 3);
    matrix[0][0] = data_size;
    matrix[0][1] = sum_x;
    matrix[0][2] = sum_y;
    matrix[1][0] = sum_x;
    matrix[1][1] = sum_product(x_values, x_values); //sum(x^2)
    matrix[1][2] = sum_product(x_values, y_values); //sum(xy)
    std::cout << "the required augmented matrix is" << std::endl;
    matrix::print2Darray(matrix);

    auto soln = solve_gauss_jordan(matrix);
    std::cout << "solution :" << std::endl;

    std::cout<<"soln[0]"<<soln[0]<<std::endl;
    std::cout<<"a="<<exp(soln[0])<<std::endl;
    std::cout<<"b="<<soln[1]<<std::endl;
    return 0;
}