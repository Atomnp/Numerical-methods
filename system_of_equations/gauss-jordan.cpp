#include <iostream>
#include <vector>
#include <fstream>
#include "../headers/matrix.h"
using Matrix=std::vector<std::vector<double>>;

std::vector<double> gauss_jordan(Matrix matrix){
    std::cout<<"inital matrix"<<std::endl;
    matrix::print2Darray(matrix);
    int n=matrix.size();
    int cols=matrix[1].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i )continue;
            double factor=matrix[j][i]/matrix[i][i];
            for(int k=i;k<cols;k++){
                matrix[j][k]=matrix[j][k]-factor*matrix[i][k];
            }
        }
    }
    matrix::print2Darray(matrix);
    std::vector<double>soln;
    int lastCol=matrix[0].size()-1;
    for(int i=0;i<n;i++){
        soln.push_back(matrix[i][lastCol]/matrix[i][i]);
    }
    return soln;
}

int main(){
    std::string filename="./input.txt";
    std::ifstream fin(filename);
    std::cout<<"give me number of rows and column of the matrix"<<std::endl;
    int rows,cols;
    std::cin>>rows>>cols;
    std::vector<std::vector<double>>matrix(rows,std::vector<double>(cols,0));

    int lineNumber=0;
    int colNumber=0;
    while(lineNumber<rows){
        // std::cout<<"line"<<lineNumber<<"col"<<colNumber<<std::endl;
        fin>>matrix[lineNumber][colNumber];
        if(colNumber==cols-1){
            colNumber=0;
            lineNumber++; 
        }else{
            colNumber++;
        }
    }
    matrix::print2Darray(matrix);
    std::vector<double> soln =gauss_jordan(matrix);
    for(auto item:soln){
        std::cout<<item<<" ,";
    }

}