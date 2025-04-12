#include <iostream>
using namespace std;
struct Employee
{
    string name;
    string id;
    double salary;
};

int main(){
    Employee emp, *ptr_emp;
    ptr_emp = &emp;
    cout<<"Enter the details of the employee:"<<endl;
    cout<<"Name:"<<endl;
    cin>>ptr_emp ->name;
    cout<<"ID:"<<endl;
    cin>>ptr_emp->id;
    cout<<"Salary:"<<endl;
    cin>>ptr_emp->salary;
    cout<<"You Entered the following details: "<<endl;
    cout<<"Name: "<<ptr_emp->name<<endl;
    cout<<"ID: "<<ptr_emp->id<<endl;
    cout<<"Salary: "<<ptr_emp->salary<<endl;
}