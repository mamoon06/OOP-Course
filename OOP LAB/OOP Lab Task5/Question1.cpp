#include <iostream>
using namespace std;
struct Rectangle
{
    float Length;
    float Width;
};
float calculateArea(Rectangle);
int main(){
    Rectangle r1;
    cout<<"Enter the length and width of the rectangle(in cm):"<<endl;
    cin>>r1.Length>>r1.Width;
    cout<<"The area of the rectagle is: "<<calculateArea(r1)<<" cm^2"<<endl;
}
float calculateArea(Rectangle r){
    return r.Length*r.Width;
}