#include <iostream>
#include <string>
using namespace std;

void Input(int(*)[3], int, string[], string[]);
void Display(int(*)[3], int, string[], string[]);
void average(int(*)[3], int);
void highest_marks(int(*)[3], int, string[], string[]);
int main(){
    int students;
    cout<<"Enter the number of students"<<endl;
    cin>>students;
    string names[students];
    string roll_num[students];
    int Marks[students][3];
    int options;
    do
    {
        cout<<"Choose one of the options:"<<endl;
        cout<<"1. Input Student Data."<<endl;
        cout<<"2. Display All The Data."<<endl;
        cout<<"3. Calculate Average Marks."<<endl;
        cout<<"4. Display The Student with Highest Marks."<<endl;
        cout<<"5. End Program.(Any number different from above will end the program.)"<<endl;
        cin>>options;
        switch (options)
        {
        case 1:
            Input(Marks, students, names, roll_num);
            break;
        case 2:
            Display(Marks, students, names, roll_num);
            break;
        case 3:
            average(Marks, students);
            break;
        case 4:
            highest_marks(Marks, students, names, roll_num);
            break;
        default:
            break;
        }
    } while (options >= 1 && options <= 4);    
}
void Input(int marks[][3], int size, string name[], string roll[]){
    for (int i = 0; i < size; i++)
    {
        cout<<"For Student "<<i+1<<endl;
        cout<<"Name: ";
        cin>>name[i];
        cout<<"Roll Number: ";
        cin>>roll[i];
        cout<<"Marks in three subjects: ";
        for (int j = 0; j < 3; j++)
        {
            cin>>marks[i][j];
        }
    }
}
void Display(int marks[][3], int size, string name[], string rollnum[]){
    for (int i = 0; i < size; i++)
    {
        cout<<"Name: "<<name[i]<<endl;
        cout<<"Roll Number: "<<rollnum[i]<<endl;
        cout<<"Marks: ";
        for (int j = 0; j < 3; j++)
        {
            cout<<marks[i][j]<<" ";
        }
        cout<<endl<<"----------------------"<<endl;
    }
    
}
void average(int marks[][3], int size){
    for (int i = 0; i < size; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + marks[i][j];
        }
        cout<<"Student "<<i+1<<" average marks = "<<sum/3<<endl;
    }
    
}
void highest_marks(int marks[][3], int size, string name[], string rollnum[]){
    int sum_arr[size];
    string NAME, ROLL;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + marks[i][j];
        }
        sum_arr[i] = sum;
    }
    int max = sum_arr[0];
    for (int i = 0; i < size; i++)
    {
        if (sum_arr[i]>max)
        {
            max = sum_arr[i];
            NAME = name[i];
            ROLL = rollnum[i];
        }
    }
    cout<<"The student with the highest marks is: "<<endl;
    cout<<"Name: "<<NAME<<endl;
    cout<<"Roll Number: "<<ROLL<<endl;
    cout<<"Marks: "<<max<<endl;
    
}