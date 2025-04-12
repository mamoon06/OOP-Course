#include <iostream>
#include <cstring>
using namespace std;
class Person{
public:
    string* Name;
    int Check;
    Person(string name = "Unknown", int check = 0) : Check(check){
        Name = new string;
        *Name = name;
    }
    Person( Person& person){
        if (person.Check==1)
        {
            *Name = *person.Name;
            Check = person.Check;
        }
    }
    ~Person(){
        delete Name;
        Name = nullptr;
    }
    void display(){
        cout<<"Address of Name: "<<Name<<endl;
        cout<<"Name: "<<*Name<<endl;
    }
};
int main(){
    Person person1("Ali", 0);
    Person person2, person3;
    person2.display();
    person2=person1;
    cout<<"Shallow Copy:"<<endl;
    cout<<"Person 1 Details:"<<endl;
    person1.display();
    cout<<"Person 2 Details:"<<endl;
    person2.display();

    
    person1.Check=1;
    person3=person1;
    cout<<"Deep Copy:"<<endl;
    cout<<"Person 1 Details:"<<endl;
    person1.display();
    cout<<"Person 3 Details:"<<endl;
    person3.display();

}