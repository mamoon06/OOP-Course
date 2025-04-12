#include <iostream>
using namespace std;
struct Point
{
    int x, y;
};
void translation(Point*, int, int, int);
void display(const Point*, int);
int main(){
    int n;
    cout<<"Enter the number of points: "<<endl;
    cin>>n;
    Point* points = new Point[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter point "<<i+1<<" (x, y)"<<endl;
        cin>>points[i].x>>points[i].y;
    }
    int dx, dy;
    cout<<"Enter the point for translation(dx, dy):"<<endl;
    cin>>dx>>dy;
    cout<<"Orignal Points:"<<endl;
    display(points, n);
    translation(points, n, dx, dy);
    cout<<"Translated Points:"<<endl;
    display(points, n);

    delete[] points;
    points = nullptr;
}
void translation(Point* points, int n, int dx, int dy){
    for (int i = 0; i < n; i++)
    {
        points[i].x += dx;
        points[i].y += dy;
    }
}
void display(const Point* points, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"("<<points[i].x<<", "<<points[i].y<<")"<<endl;
    }
}