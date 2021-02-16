#include <iostream>
#include <vector>
#include <fstream>

struct Point{
    double x;
    double y;
    Point (double x=0,double y=0):x(x),y(y){}
};
void printData(std::string filename){
    std::cout<<"inputs data are"<<std::endl;
    std::string line;
    std::ifstream fin(filename);
    while(getline(fin,line)){
        std::cout<<line<<std::endl;
    }
}
int main(){
    std::vector<Point>points;
    std::string filename="./input.txt";
    try{
        std::ifstream fin(filename);
        if(fin.is_open()){
            printf("file opened sucessfully");
        }
        double a,b;
        while(fin>>a>>b){
            std::cout<<"("<<a<<","<<b<<")"<<std::endl;
            points.push_back(Point(a,b));        
        }
        fin.close();
        double x;
        printData(filename);
        printf("Enter the value of x:");
        std::cin>>x;

        double result=0;
        for(int i=0;i<points.size();i++){
            double intermediate=points[i].y;
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                intermediate*=(x-points[j].x)/(points[i].x-points[j].x);
            }
            result+=intermediate;
            
        }

        printData(filename);
        std::cout<<"for x ="<<x<<" , y= "<<result<<std::endl;

    }
    catch(std::exception e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}