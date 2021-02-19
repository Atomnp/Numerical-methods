#include <iostream>
#include <cmath>
//our algebraic function whose roots need to be determined
double f(double x){
    return (x *sin(x) + cos(x)) ;
}
//derivative of above function
double df(double x){
    return x*cos(x) ;
}
 double abs(double x){
     if(x<0){
         return -1*x;
     }
     else return x;
 }
int main(){
    double tolerance=0.0001;
    std::cout<<"hello world"<<std::endl;
    //initial guess
    double x=2;
    while(abs(f(x))>tolerance){
        //new guess 
        x=x-f(x)/df(x);
        std::cout<<"guess x= "<<x<<std::endl;
    }
    std::cout<<"Final x= "<<x<<std::endl;

}