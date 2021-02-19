#include <iostream>
#include <cmath>

//represents dy/dx=RETURN_VALUE
//you chan change the function by changing this return value
double df(double x, double y){
    return log10(x+y);
}

int main(){
    double x_init,y_init,x_to_find,n;
    std::cout<<"input initial value"<<std::endl;
    std::cin>>x_init>>y_init;
    std::cout<<"Where to find y? input x: ";
    std::cin>>x_to_find;
    std::cout<<"Number of steps? input :";
    std::cin>>n;
    double h=(x_to_find-x_init)/n;
    double x=x_init;
    double y=y_init;
    double tolerance=0.001;
    std::cout<<"when x="<<x_init<<" ,y = "<<y_init<<std::endl;
    for(int i=0;i<n;i++){
        //this is exactly euler's formula
        double y_new=y+h*df(x_init+i*h,y);
        double y_old=y;
        std::cout<<"when x="<<x_init+(i+1)*h<<"y = "<<y_new<<std::endl;
        //modify the obtained value of y untill we get required accuracy
        while(y_new-y_old>tolerance ){
            double mean_slope=(df(x_init+i*h,y)+df(x_init+(i+1)*h,y_new))/2;
            y_old=y_new;
            y_new=y+h*mean_slope;
            std::cout<<"when x="<<x_init+(i+1)*h<<"y = "<<y_new<<std::endl;
        }
        y=y_new;
        std::cout<<"--------------------"<<std::endl;

    }
    
}