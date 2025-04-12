#include <iostream>
using namespace std;
class Person
{
protected:
    string Name;
    string Address;
public:
    Person(string name, string address) : Name(name), Address(address){}
    void setName(string name){ Name = name; }
    void setAddress(string address){ Address = address; }

    void getName(){ cout<<Name<<endl; }
    void getAddress(){ cout<<Address<<endl; }
};
class Employee : public Person
{
protected:
    int EmployeeNum;
    int HoursWorked;
public:
    Employee(string name, string address, int empnum, int hrsW) : Person(name, address), EmployeeNum(empnum), HoursWorked(hrsW){}
    void setEmpNum(int empnum){ EmployeeNum = empnum; }
    void setHoursWorked( int hrsW){ HoursWorked = hrsW; }

    void getEmpNum(){ cout<<EmployeeNum<<endl; }
    void getHoursWorked(){ cout<<HoursWorked<<endl; }
};
class ProductionWorker : public Employee
{
protected:
    int Shift;
    double HourlyPay;
    double Salary;
public:
    ProductionWorker(string name, string address, int empnum, int hrsW, int shift, double hrlyPay) : Employee(name, address, empnum, hrsW), Shift(shift), HourlyPay(hrlyPay), Salary(0.0){}
    void setShift(int shift){ Shift = shift; }
    void setHourlyPay(double hrlyPay){ HourlyPay = hrlyPay; }
    void setSalary(double salary){ Salary = salary; }

    void getShift(){ cout<<Shift<<endl; }
    void getHourlyPay(){ cout<<HourlyPay<<endl; }
    void getSalary(){ cout<<Salary<<endl; }

    double calculateSalary(){
        Salary = HourlyPay * HoursWorked;
        if (Shift==2 && HoursWorked>5)
        {
            Salary += 1000;
        }
    }
    void print_details(){
        cout<<"Employee Details: "<<endl;
        cout<<"Name: "<<Name<<endl;
        cout<<"Address: "<<Address<<endl;
        cout<<"Employee Number: "<<EmployeeNum<<endl;
        cout<<"Hours Worked: "<<HoursWorked<<endl;
        cout<<"Shift: "<<(Shift == 1 ? "Day Shift" : "Night Shift")<<endl;
        cout<<"Hourly Pay: "<<HourlyPay<<endl;
        cout<<"Salary: "<<Salary<<endl;
        cout<<"-----------------------------------"<<endl;
    }
};
int main(){
    ProductionWorker emp1("Ali", "123 Hayatabad", 001, 9, 1, 400);
    ProductionWorker emp2("Hamza", "330 Industrial State", 002, 7, 2, 540);
    
    emp1.calculateSalary();
    emp2.calculateSalary();

    emp1.print_details();
    emp2.print_details();
}