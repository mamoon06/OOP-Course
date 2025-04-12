#include <iostream>
#include <iomanip>
using namespace std;
struct Car{
    string Brand;
    int Year;
    float Price;
};
void updatePrice(Car*, float);
int main(){
    Car car;
    float discount;
    cout<<"Enter the details of the car: "<<endl;
    cout<<"Brand: ";
    getline(cin, car.Brand);
    cout<<"Year: ";
    cin>>car.Year;
    cout<<"Price: ";
    cin>>car.Price;
    cout<<"Now enter the percent discount: ";
    cin>>discount;
    updatePrice(&car, discount/100);
    cout<<"After Discount:"<<endl;
    cout<<"Brand: "<<car.Brand<<endl;
    cout<<"Year: "<<car.Year<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Price: "<<car.Price<<endl;
}
void updatePrice(Car* c, float disc){
    c->Price -= (c->Price * disc);
}