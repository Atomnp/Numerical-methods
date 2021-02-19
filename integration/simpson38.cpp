#include <iostream>
#include <fstream>
#include <cmath>
double f(double x){
    return sin(x)-log(x)+exp(x);
}
int main(){
    int n;
    double x,y,a,b;
    std::cout<<"number of strips  : "<<std::endl;
    std::cin>>n;
    if(n%3!=0){
        std::cout<<"n should be multiple of 3"<<std::endl;
        exit(0);
    }
    std::cout<<"input a and b for the limit of integration: ";
    std::cin>>a>>b;
    double h=(b-a)/n;
    double sum=f(a)+f(b);
    x=a+h;
    for(int i=1;i<n;i++){
        std::cout<<"fx : "<<f(x)<<std::endl;
        if(i%3==0){
            sum+=2*f(x);
        }
        else{
            sum+=3*f(x);
        }
        x+=h;
    }
    sum=3*h/8*sum;
    std::cout<<"result is :  "<<sum;
    
        
    
}