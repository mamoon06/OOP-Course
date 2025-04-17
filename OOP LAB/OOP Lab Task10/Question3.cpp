#include <iostream>
using namespace std;
class Length;
class Width {
private:
    int data;
public:
    Width(int d) : data(d){}
    friend int calculateArea(Length, Width);
};
class Length {
private:
    int data;
public:
    Length(int d) : data(d){}
    friend int calculateArea(Length, Width);
};
int calculateArea(Length L, Width W){
    return L.data*W.data;
}
int main(){
    Length L(20);   Width W(30);
    cout<<"Area: "<<calculateArea(L, W)<<endl;
}