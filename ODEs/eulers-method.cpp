#include <iostream>

//represents dy/dx=RETURN_VALUE
double df(double x, double y){
    return (y-x)/(y+x);
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
    double x1=x_init;
    double y1=y_init;
    for(int i=0;i<n;i++){
        std::cout<<"when x= "<<x1<<"y ="<<y1<<std::endl;
        y1=y1+h*df(x1,y1);
        x1=x1+h;
    }
    std::cout<<"-----------------------"<<std::endl;
    std::cout<<"Final result !! when x= "<<x1<<"y ="<<y1<<std::endl;

}