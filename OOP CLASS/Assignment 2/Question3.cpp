#include <iostream>
using namespace std;
class Car{
    string Model;
    int ManufactureYear;
public:
    Car( string model, int manuYear) : Model(model), ManufactureYear(manuYear){ cout<<"Constructor Called!"<<endl; }
    ~Car(){ cout<<"Destructor Called!"<<endl; }
};
int main(){
    Car car1("Toyota", 2012), car2("Alto", 2020);
}