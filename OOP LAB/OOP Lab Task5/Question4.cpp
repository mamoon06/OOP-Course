#include <iostream>
using namespace std;
struct Student
{
    string name;
    string rollNo;
    float marks;
};
int main(){
    int n;
    cout<<"Enter the number of students:"<<endl;
    cin>>n;
    Student* stu = new Student[n];
    cout<<"Enter the data of all the students:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Student "<<i+1<<endl;
        cin.ignore();
        cout<<"Name: ";
        getline(cin, stu[i].name);
        cout<<"Roll Number: ";
        getline(cin, stu[i].rollNo);
        cout<<"Marks: ";
        cin>>stu[i].marks;
    }
    cout<<"You entered the following details:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<stu[i].name<<endl;
        cout<<stu[i].rollNo<<endl;
        cout<<stu[i].marks<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*"<<endl;
    }
    
    delete[] stu;
    stu = nullptr;
}