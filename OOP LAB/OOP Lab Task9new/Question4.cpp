#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
    string Name;
public:
    Employee(string n) {
        Name = n;
    }
    string getName(){ return Name; }
    void display(){
        cout<<"Employee: "<<Name<<endl;
    }
};
class Department {
private:
    string Name;
    Employee** employees;
    int capacity;
    int count;
    void resize() {
        int newCapacity = capacity * 2;
        Employee** newArray = new Employee*[newCapacity];
        for (int i = 0; i < count; i++) {
            newArray[i] = employees[i];
        }
        delete[] employees;
        employees = newArray;
        capacity = newCapacity;
    }
public:
    Department(string n) {
        Name = n;
        capacity = 5;
        count = 0;
        employees = new Employee*[capacity];
    }
    void addEmployee(Employee* emp) {
        for (int i = 0; i < count; i++) {
            if (employees[i] == emp) return;
        }
        if (count == capacity) resize();
        employees[count++] = emp;
    }
    void removeEmployee(Employee* emp) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (employees[i] == emp) {
                index = i;
                break;
            }
        }
        if (index == -1) return;

        for (int i = index; i < count - 1; i++) {
            employees[i] = employees[i + 1];
        }
        --count;
    }
    void displayEmployees() const {
        cout<<"Department:"<<Name<<endl;
        if (count == 0) {
            cout<<"No employees assigned."<<endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            employees[i]->display();
        }
    }
    ~Department() {
        cout <<"Department \""<<Name<<"\" is being destroyed."<<endl;
        delete[] employees;
    }
};
int main() {
    Employee* emp1 = new Employee("Ali");
    Employee* emp2 = new Employee("Ahmed");
    Employee* emp3 = new Employee("Kazmi");

    Department dept1("CS");
    Department dept2("Engineering");

    dept1.addEmployee(emp1);
    dept1.addEmployee(emp2);

    dept2.addEmployee(emp2);
    dept2.addEmployee(emp3);

    cout<<endl<<"-- Department 1 --"<<endl;
    dept1.displayEmployees();

    cout<<endl<<"-- Department 2 --"<<endl;
    dept2.displayEmployees();

    dept1.removeEmployee(emp2);
    cout<<endl<<"-- Department 1 After Removing Bob --"<<endl;
    dept1.displayEmployees();
    
    cout<<endl<<"-- Employees Still Exist --"<<endl;
    emp1->display();
    emp2->display();
    emp3->display();

    delete emp1;
    delete emp2;
    delete emp3;
}