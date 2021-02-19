#include <iostream>

//represents dy/dx=RETURN_VALUE
double df(double x, double y){
    return (y+x);
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
        double yn=y+h*df(x_init+i*h,y);
        std::cout<<"when x="<<x_init+(i+1)*h<<" ,y = "<<yn<<std::endl;
        double mean_slope=(df(x_init+i*h,y)+df(x_init+(i+1)*h,yn))/2;
        std::cout<<"mean slope ="<<mean_slope<<std::endl;
        
        double y_new=y+h*mean_slope;
        double y_old=yn;
        std::cout<<"when x="<<x_init+(i+1)*h<<"y = "<<y_new<<std::endl;
        std::cout<<"y_old="<<y_old<<"y _new= "<<y_new<<std::endl;
        int count =0;
        while(y_new-y_old>tolerance and count<10){
            double mean_slope=(df(x_init+i*h,y)+df(x_init+(i+1)*h,y_new))/2;
            y_old=y_new;
            y_new=y+h*mean_slope;
            std::cout<<"when x="<<x_init+(i+1)*h<<"y = "<<y_new<<std::endl;
            count++;
        }
        y=y_new;
        std::cout<<"--------------------"<<std::endl;

    }
    
}