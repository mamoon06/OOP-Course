#include <iostream>
using namespace std;
class Force;
class Particle {
private:
    double Velocity;
    double Acceleration;
public:
    Particle(double v, double a) : Velocity(v), Acceleration(a){}
    void display(){
        cout<<"Velocity = "<<Velocity<<", Acceleration = "<<Acceleration<<endl;
    }
    friend class Force;
};
class Force {
public:
    void modify(Particle p, double time){
        p.Velocity += p.Acceleration*time;
        cout<<"Velocity after time "<<time<<" s = "<<p.Velocity<<" m/s"<<endl;
    }
};
int main(){
    Particle p(23, 5);
    Force f;
    f.modify(p, 10);
}