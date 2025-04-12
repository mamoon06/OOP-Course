#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string Name;
    string Rollnum;
    float Marks[3];
public:
    void store_data(string, string, float*);
    void display_data(int, Student*);
    void average_marks(int, Student*);
    void highest_marks(int, Student*);
};
int main(){
    int n;
    cout<<"Enter the total Number of students:"<<endl;
    cin>>n;
    Student stu[n];
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        string name, roll;
        float marks[3];
        cout<<"Enter name, roll no. and marks in sequence:"<<endl;
        getline(cin, name);
        getline(cin, roll);
        for (int j = 0; j < 3; j++)
        {   cin>>marks[j];          }
        stu[i].store_data(name, roll, marks);
    }
    int option;
    do
    {
        cout<<"Choose one of the following actions:"<<endl;
        cout<<"(1) Display Data"<<endl<<"(2) Calculate Average Marks"<<endl<<"(3) Highest Marks"<<endl;
        cout<<"(4) End Program"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            stu->display_data(n, stu);
            break;
        case 2:
            stu->average_marks(n, stu);
            break;
        case 3:
            stu->highest_marks(n, stu);
        default:
            break;
        }
    } while (option != 4);
    
}
void Student::store_data(string name, string roll, float* marks){
    Name = name;
    Rollnum = roll;
    for (int i = 0; i < 3; i++)
    {
        Marks[i] = marks[i];
    }
}
void Student::display_data(int n, Student* stu){
    cout<<"You Entered the following data:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Name: "<<stu[i].Name<<endl;
        cout<<"Roll Number: "<<stu[i].Rollnum<<endl;
        cout<<"Marks: ";
        for (int j = 0; j < 3; j++)
        {
            cout<<stu[i].Marks[j]<<" ";
        }
        cout<<endl<<endl;
    }
}
void Student::average_marks(int n, Student* stu){
    float sum=0;
    for (int i = 0; i < n; i++)
    {
        sum=0;
        cout<<"Name: "<<stu[i].Name<<endl;
        for (int j = 0; j < 3; j++)
        {
            sum += stu[i].Marks[j];
        }
        cout<<"Average Marks: "<<sum/3<<endl<<endl;
    }
}
void Student::highest_marks(int n, Student* stu){
    float sum[n]={0};
    int p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum[i] += stu[i].Marks[j];
        }
    }
    float max = sum[0];
    for (int i = 0; i < n-1; i++)
    {
        if (max<sum[i])
        {
            max=sum[i];
            p=i;
        }
    }
    cout<<"The Student with the Highest marks is:"<<endl;
    cout<<"Name: "<<stu[p].Name<<endl;
    cout<<"Roll Number: "<<stu[p].Rollnum<<endl;
    cout<<"Total Marks: "<<max<<endl;
}