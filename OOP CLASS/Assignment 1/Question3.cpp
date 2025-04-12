#include <iostream>
using namespace std;
struct Student
{
    char Name[50];
    int numSubjects;
    int* Scores;
};
void average_score(const Student*, float*, int);
void sort_by_average(Student*, float*, int);
int main(){
    int n;
    cout<<"Enter the number of students you want to enter the details of:"<<endl;
    cin>>n;
    Student stu[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the details of student "<<i+1<<endl;
        cout<<"Name:"<<endl;
        cin>>stu[i].Name;
        cout<<"Number of subjects:"<<endl;
        cin>>stu[i].numSubjects;
        stu[i].Scores = new int[stu[i].numSubjects];
        cout<<"Enter the scores of each subject:"<<endl;
        for (int j = 0; j < stu[i].numSubjects; j++)
        {
            cin>>stu[i].Scores[j];
        }   
    }
    float average[n];
    average_score(stu, average, n);
    sort_by_average(stu, average, n);
    for (int i = 0; i < n; i++)
    {
        cout<<"Name: "<<stu[i].Name<<"\t"<<"Average Score: "<<average[i]<<endl;
    }
    
    for (int i = 0; i < n; i++) {
        delete[] stu[i].Scores;
        stu[i].Scores = nullptr;
    }
}
void average_score(const Student* stu, float* average, int size){
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum=0;
        for (int j = 0; j < stu[i].numSubjects; j++)
        {
            sum += stu[i].Scores[j];
        }
        average[i] = (float)sum/stu[i].numSubjects;
    }
}
void sort_by_average(Student* stu, float* average, int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (average[j]<average[j+1])
            {
                swap(stu[j], stu[j+1]);
                swap(average[j], average[j+1]);
            }
        }
    }
}