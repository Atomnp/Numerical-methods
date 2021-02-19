#include <iostream>
#include <cmath>

//represents dy/dx=RETURN_VALUE
//you chan change the function by changing this return value
double df(double x, double y,double z){
    return (1+x*z);
}
double dg(double x, double y,double z){
    return (-1*x*y) ;
}

int main(){
    double x_init,y_init,z_init,x_to_find,n;
    std::cout<<"input initial value of x y and z"<<std::endl;
    std::cin>>x_init>>y_init>>z_init;
    std::cout<<"Where to find y? input x: ";
    std::cin>>x_to_find;
    std::cout<<"Number of steps? input :";
    std::cin>>n;
    double h=(x_to_find-x_init)/n;
    double x=x_init;
    double y=y_init;
    double z=z_init;
    double tolerance=0.001;
    std::cout<<"when x="<<x_init<<" ,y = "<<y_init<<std::endl;
    for(int i=0;i<n;i++){
        //now we determine k1,k2,k3 and k4
        double k1=h*df(x,y,z);
        double l1=h*dg(x,y,z);
        double k2=h*df(x+h/2,y+k1/2,z+l1/2);
        double l2=h*dg(x+h/2,y+k2/2,z+l1/2);
        double k3=h*df(x+h/2,y+k2/2,z+l2/2);
        double l3=h*dg(x+h/2,y+k3/2,z+l2/2);
        double k4=h*df(x+h,y+k3,z+l3);
        double l4=h*dg(x+h,y+k3,z+l3);

        //now calculate the value of from these values
        double k=(k1+2*k2+2*k3+k4)/6;
        double l=(l1+2*l2+2*l3+l4)/6;
        y=y+k;
        z=z+l;
        x=x+h;
        std::cout<<"when x= "<<x<<" y= "<<y<<" z= "<<z<<std::endl;
    }
    
}