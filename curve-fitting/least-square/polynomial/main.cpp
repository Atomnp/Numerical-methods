#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include "../../../headers/matrix.h"
#include<fstream>

double calculate_sum(const std::vector<double>&x,const std::vector<double>&y,int pow_x,int pow_y){
    //calculate something like sum(xsq,y) here in this pow_x=2,pow_y=1
    assert(x.size()==y.size());
    double sum=0;
    for(int i=0;i<x.size();i++){
        sum+=pow(x[i],pow_x)*pow(y[i],pow_y);
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
int main(){
    std::string filename="./input.txt";
    std::ifstream fin(filename);
    std::vector<double>x;
    std::vector<double>y;
    int data_size;
    double a,b;
    while(fin>>a>>b){
        x.push_back(a);
        y.push_back(b);
        data_size++;
    }
    /*
    matrix is formed in this form

        n           sum(x)      sum(x^2)        sum(y)
        sum(x)      sum(x^2)    sum(x^3)        sum(xy)
        sum(x^2)    sum(x^3)    sum(x^4)        sum(x^2y)


    */

   int degree;
   std::cout<<"Tell me what degree soln you need"<<std::endl;
   std::cin>>degree;

   //generate 2d vector with degree+1 rows and degree+2 cols 
   std::vector<std::vector<double>> matrix(degree+1, std::vector<double>(degree+2, 0));
   matrix::print2Darray(matrix);
  
   for(int i=0;i<=degree;i++){
       for(int j=0;j<=degree+1;j++){
           if(i==0 and j==0){
                matrix[0][0]=data_size;
                continue;
           }
           //because the pattern of the righmost col is different
           if(j==degree+1){
               matrix[i][j]=calculate_sum(x,y,i,1);
           }
           else{
               matrix[i][j]=calculate_sum(x,y,i+j,0);
           }
           
       }
   }
   printf("the constructed matrix is \n");
   matrix::print2Darray(matrix);
   auto soln = solve_gauss_jordan(matrix);
    std::cout << "solution :" << std::endl;
    for (int i = 0; i < soln.size(); i++)
    {
        std::cout << soln[i] << std::endl;
    }

}