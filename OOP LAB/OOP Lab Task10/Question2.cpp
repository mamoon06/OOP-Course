#include <iostream>
#include <math.h>
using namespace std;
class PointB;
class PointA {
private:
    int X, Y;
public:
    PointA(int x, int y) : X(x), Y(y){}
    friend int calculateDistance(PointA, PointB);
};
class PointB {
private:
    int X, Y;
public:
    PointB(int x, int y) : X(x), Y(y){}
    friend int calculateDistance(PointA, PointB);
};
int calculateDistance(PointA ptr1, PointB ptr2){
    return sqrt((ptr1.X-ptr2.X)*(ptr1.X-ptr2.X) + (ptr1.Y-ptr2.Y)*(ptr1.Y-ptr2.Y));
}
int main(){
    PointA ptr1(2, 3);
    PointB ptr2(5, 5);
    cout<<"Distance: "<<calculateDistance(ptr1, ptr2)<<endl;
}