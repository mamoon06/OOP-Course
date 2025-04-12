#include <iostream>
using namespace std;
class Employee{
protected:
    string Name;
    string Id;
    double Salary;
public:
    Employee(string name, string id, double salary) : Name(name), Id(id), Salary(salary){}
    void display(){
        cout<<"Name: "<<Name<<endl;
        cout<<"ID: "<<Id<<endl;
        cout<<"Salaray: "<<Salary<<endl;
    }
};
class Manager : public Employee{
protected:
    string Department;
public:
    Manager(string name, string id, double salary, string depart) : Employee(name, id, salary), Department(depart){}
    void display(){
        Employee::display();
        cout<<"Department: "<<Department<<endl;
    }
};
int main(){
    Manager man1("Ali", "@4p310", 20000, "CS");
    Employee emp1("Ahmed", "3097p2", 18000);
    man1.display();
    emp1.display();
}