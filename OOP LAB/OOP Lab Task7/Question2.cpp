#include <iostream>
using namespace std;
class Car
{
private:
    int currentSpeed;
    static int maxSpeed;
public:
    void setspeed(int speed){
        currentSpeed = speed;
        if (speed>maxSpeed)
        {
            maxSpeed = speed;
        }
    }
    static void getMaxspeed(){
        cout<<"Max Speed = "<<maxSpeed<<" km/h"<<endl;
    }
};
int Car::maxSpeed=0;
int main(){
    Car car1, car2, car3, car4;
    car1.setspeed(128);
    car2.setspeed(85);
    car3.setspeed(150);
    car4.setspeed(133);
    Car::getMaxspeed();
}