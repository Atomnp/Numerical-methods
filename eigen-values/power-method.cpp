//this program solves dominant eigen value of a given matrix using matrix method
#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <cmath>
#include <sstream>
#include "../headers/matrix.h"

using Matrix=std::vector<std::vector<double>>;
//to print vector as verticel column vector
void print(std::vector<double>arr){
    std::cout<<"\n[\n";
    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i]<<std::endl;
        if(i==arr.size()-1){
            std::cout<<"]"<<std::endl;
        }
    }
}
//to calculate absolute value
double abs(double a){
    return a<0?-1*a:a;
}

//for the multiplication of matrix and vector
std::vector<double>matrix_vector_mul(const Matrix &matrix,const std::vector<double>&vec){
    assert(matrix[0].size()==vec.size() && "cant multiply this matrix and vector");
    //multiplication logic
    std::vector<double>result;
    for(int i=0;i<matrix.size();i++){
        double sum=0;
        for(int j=0; j<vec.size();j++){
            sum+=matrix[i][j]*vec[j];
        }
        result.push_back(sum);
    }
    return result;
}
int main(){
    std::string filename="./input.txt";
    std::ifstream fin(filename);
    int linenumber=0;
    std::string line;
    std::cout<<"give me number of rows and column of the matrix"<<std::endl;
    int rows,cols;
    std::cin>>rows>>cols;
    std::vector<std::vector<double>>matrix(rows,std::vector<double>(cols,0));
    while(getline(fin,line)){
        std::istringstream iss(line);
        int a;
        int col=0;
        while(iss>>a){
            matrix[linenumber][col++]=a;
        }
        linenumber++;
    }
    matrix::print2Darray(matrix);
    //guessing initial eigen vector
    float tolorable_error=0.001;
    bool solved=false;
    std::vector<double>x(rows,1);
    std::vector<double>error(rows,0);
    double lambda=0;
    
    for(int i=0;i<100;i++){
        auto z=matrix_vector_mul(matrix,x);
        print(z);
        //find max abs value from the vector z and take common the value common is 
        //out first approximation to the eigenvalue/lambda
        lambda=0;
        for(int i=0;i<z.size();i++){
            if(abs(z[i]>abs(lambda))){
                lambda=z[i];
            }
        }
        for(int i=0;i<z.size();i++){
            z[i]=z[i]/lambda;
        }

        //calculate the error vector
        double max_error=0;
        for(int i=0;i<z.size();i++){
            error[i]=z[i]-x[i];
            if(abs(error[i])>max_error){
                max_error=abs(error[i]);
            }
        }
        //if error is tolorable quit calculation
        if(max_error<=tolorable_error){
            
            solved=true;
            break;
        }
        //set x to new matrix obtained after multiplication
        x=z;
    }
    if(solved){
        std::cout<<"the solution is"<<std::endl;
        std::cout<<"eigen value="<<lambda<<std::endl;
        std::cout<<"eigen vector"<<std::endl;
        print(x);
        std::cout<<"normalized form"<<std::endl;
        double magnitude;
        for(int i=0;i<x.size();i++){
            magnitude+=pow(x[i],2);
        }
        magnitude=sqrt(magnitude);
        std::vector<double>normalized(x.size());
        for(int i=0;i<x.size();i++){
            normalized[i]=x[i]/magnitude;
        }
        print(normalized);

    }


}