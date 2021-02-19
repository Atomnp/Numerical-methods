#include <iostream>
#include <fstream>
int main(){
    int n;
    double sum=0,y,a,b;
    std::cout<<"number of data : "<<std::endl;
    std::cin>>n;
    std::cout<<"input a and b for the limit of integration: ";
    std::cin>>a>>b;
    double h=(b-a)/(n-1);
    for(int i=0;i<n;i++){
        std::cout<<"Ender data number "<<i+1<<": ";
        std::cin>>y;
        if(i==0 or i==n-1){
            std::cout<<"here"<<i<<"  "<<y<<std::endl;
            sum+=y;
        }else{
            sum+=2*y;
        }
       
        
    }

    sum=h/2*sum;
    std::cout<<"result is :  "<<sum;
    
        
    
}