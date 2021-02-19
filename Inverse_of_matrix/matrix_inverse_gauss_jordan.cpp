#include <iostream>
#include <vector>
#include <fstream>
#include "../headers/matrix.h"
using Matrix=std::vector<std::vector<double>>;

void inverse_gauss_jordan(Matrix matrix){
    int n=matrix.size();
    std::vector<std::vector<double>>inverse(n,std::vector<double>(n,0));
    for(int i=0;i<n;i++){
        inverse[i][i]=1;
    }
   
    int cols=matrix[1].size();
    for(int i=0;i<n;i++){
        double pivot=matrix[i][i];
        if(pivot==0){
            std::cout<<"can't calculate the inverse of the given matrix"<<std::endl;
            exit(0);
        }
        for(int k=0;k<cols;k++){
            
            matrix[i][k]=matrix[i][k]/pivot;
            inverse[i][k]=inverse[i][k]/pivot;
        }
        
        for(int j=0;j<n;j++){
            if(j==i )continue;
            double factor=matrix[j][i]/matrix[i][i];
            for(int k=0;k<cols;k++){
                matrix[j][k]=matrix[j][k]-factor*matrix[i][k];
                inverse[j][k]=inverse[j][k]-factor*inverse[i][k];
            }
            
        }
    }
    std::cout<<"the inverse of the matrix"<<std::endl;
    matrix::print2Darray(matrix);
    std::cout<<"is => "<<std::endl;
    matrix::print2Darray(inverse);
   
}

int main(){
    std::string filename="./input.txt";
    std::ifstream fin(filename);
    std::cout<<"give me number of rows and column of the matrix stored in file"<<std::endl;
    int rows=3,cols=3;
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
    // matrix::print2Darray(matrix);
    inverse_gauss_jordan(matrix);


}