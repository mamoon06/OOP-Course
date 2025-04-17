#include <iostream>
using namespace std;
class Engine {
public:
    void engStart(){ cout<<"Engine Started!"<<endl; }
};
class Car {
private:
    Engine engine;
public:
    void carStart(){
        engine.engStart();
        cout<<"Car Working!"<<endl;
    }
};
int main(){
    Car car1;
    car1.carStart();
}