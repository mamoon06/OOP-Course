#include <iostream>
using namespace std;
class Employee
{
    const double Salary;
    int Id;
public:
    Employee(int id, double salary) : Id(id), Salary(salary){
        cout<<"Employee address: "<<this<<endl;
        cout<<"Employee Id: "<<Id<<"    Salary: "<<Salary<<endl;
    }
};
int main(){
    Employee emp1(1234, 200000), emp2(1111, 150000);
    
}