#include <iostream>
using namespace std;
class Rectangle{
    float Length;
    float Breadth;
public:
    Rectangle(float len=0, float bret=0) : Length(len), Breadth(bret) {}
    Rectangle(Rectangle& rectangle){
        Length = rectangle.Length;
        Breadth = rectangle.Breadth;
    }
    void input(float len, float bret){ Length=len;  Breadth=bret; }
    void display(){
        cout<<"Length: "<<Length<<"   Breadth: "<<Breadth<<endl;
    }
};
int main(){
    Rectangle rec1(3.5, 9.2);
    Rectangle rec2;
    cout<<"Before Copy"<<endl;
    cout<<"Rectangle 1 atributes: "<<endl;
    rec1.display();
    cout<<"Rectangle 2 atributes:"<<endl;
    rec2.display();
    cout<<"After Copy"<<endl;
    cout<<"Rectangle 1 atributes: "<<endl;
    rec1.display();
    rec2 = rec1;
    cout<<"Rectangle 2 atributes:"<<endl;
    rec2.display();
}