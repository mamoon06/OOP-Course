#include <iostream>
using namespace std;
class Address {
public:
    string house, street, city;
    Address(string h, string s, string c): house(h), street(s), city(c){}
};
class Student {
private:
    string Name;
    Address *address;
public:
    Student(string n, Address *add){
        Name = n;
        address = add;
    }
    void display(){
        cout<<"Name: "<<Name<<endl;
        cout<<"Address: "<<address->house<<", "<<address->street<<", "<<address->city<<endl;
    }
};
int main(){
    Address add("13", "I/11", "Peshawar");
    Student stu("Ali", &add);
    stu.display();
}