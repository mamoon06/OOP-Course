#include <iostream>
using namespace std;
class Shape{
private:
    double Area;
protected:
    void calculateArea(double area){ Area = area; }
public:
    void displayArea(){ cout<<"Area = "<<Area<<endl; }
};
class Circle : public Shape{
private:
    double Radius;
protected:
    void calculateArea(){
        Shape::calculateArea(3.14*Radius*Radius);
    }
public:
    Circle(double r=0) : Radius(r){ calculateArea(); }
};
int main(){
    Circle c1(4.5);
    c1.displayArea();
}