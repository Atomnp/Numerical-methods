#include <iostream>
#include <cmath>
 double f(double x){
     return x*sin(x)+cos(x);
 }
 double abs(double x){
     if(x<0){
         return -1*x;
     }
     else return x;
 }
 int main(){
     double tolerance=0.00001,c;
     int maxIt=100,iteration=0;;
     //initial interval
     double a=2,b=3;
     if(f(a)*f(b)>0){
         std::cout<<"this interval may not contain the solution"<<std::endl;
         exit(0);
     }
     //dont use abs function from the cmath library because it only works for integers
     while(abs(f(c))>tolerance and iteration<maxIt){
         c=(a+b)/2;
         std::cout<<"c :"<<c<<std::endl;
         //if c and a both have same sign then the solution not lie between
         if(f(c)*f(a)>0){
             a=c;
         }
         else{
             b=c;
         }
         iteration++;
     }
     std::cout<<"iteration"<<iteration<<" The final Result is"<<c<<std::endl;
 }