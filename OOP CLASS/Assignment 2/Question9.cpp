#include <iostream>
using namespace std;
class Vehicle{
public:
    void startEngine() {
        cout<<"Vehicle engine started."<<endl;
    }
};
    
class Airplane : public Vehicle{
public:
    void startEngine() {
        cout<<"Airplane engine starting."<<endl;
    }
};
int main() {
    Vehicle vehicle;
    Airplane airplane;
    
    cout<<"Base class function call:"<<endl;
    vehicle.startEngine();
        
    cout<<"Derived class function call:"<<endl;
    airplane.startEngine();
    
}