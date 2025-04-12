#include <iostream>
using namespace std;
class Employee
{
    string Name;
    int Id;
    static int Count;
public:
    Employee(string name, int id) : Name(name), Id(id){ Count++; }
    static void EmpNum(){ cout<<"Number of Employees: "<<Count<<endl; }
};
int Employee::Count=0;
int main(){
    Employee emp1("Ali", 001), emp2("Ahmed", 002), emp3("Hadi", 003);
    Employee::EmpNum();
}