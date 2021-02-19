#include <iostream>
#include <cmath>
double f(double x){
    return (exp(x) + sin(x) - 4) ;
}
 double abs(double x){
     if(x<0){
         return -1*x;
     }
     else return x;
 }
int main(){
    int tolerance=0.0001;
    //initial guesses
    double a=1.5,b=1.7,c=5;
    int maxIter=100,iter=0;
    while(abs(f(c))>tolerance and iter<maxIter){
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        iter++;
    }
    std::cout<<"final approximation of the root "<<c<<std::endl;
    

}