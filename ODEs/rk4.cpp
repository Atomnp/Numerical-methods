#include <iostream>
#include <cmath>

//represents dy/dx=RETURN_VALUE
//you chan change the function by changing this return value
double df(double x, double y){
    return (pow(y,2)-pow(x,2))/(pow(y,2)+pow(x,2));
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
        //now we determine k1,k2,k3 and k4
        double k1=h*df(x,y);
        double k2=h*df(x+h/2,y+k1/2);
        double k3=h*df(x+h/2,y+k2/2);
        double k4=h*df(x+h,y+k3);

        //now calculate the value of from these values
        double k=(k1+2*k2+2*k3+k4)/6;
        y=y+k;
        x=x+h;
        std::cout<<"when x="<<x<<"y= "<<y<<std::endl;
    }
    
}