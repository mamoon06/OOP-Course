#include <iostream>
using namespace std;
struct Student
{
    string Name;
    string Roll_num;
    float Gpa;
};
struct Professor
{
    string Name;
    string Id;
    string Subject;
};
struct Course
{
    string Code;
    Student* students;
    int stu_count;
    Professor professor;
};
struct University
{
    Course* courses;
};
void display(const University, int);
void input_data(University*, int);
void enroll_stu(University*, int*);
void update_gpa(University*, int);
void remove_stu(University*, int*);
int main(){
    int n, options;
    cout<<"Enter the number of courses and students in each course:"<<endl;
    cin>>n;
    University uni;
    uni.courses = new Course[n];
    do
    {
        cout<<"Choose one of the following operation:"<<endl;
        cout<<"(1) Input Data"<<endl<<"(2) Display Data"<<endl;
        cout<<"(3) Enroll New Students"<<endl<<"(4) Remove Students"<<endl;
        cout<<"(5) Update GPA"<<endl<<"(6) End Program"<<endl;
        cin>>options;
        cin.ignore();
        switch (options)
        {
        case 1:
            input_data(&uni, n);
            break;
        case 2:
            display(uni, n);
            break;
        case 3:
            enroll_stu(&uni, &n);
            break;
        case 4:
            remove_stu(&uni, &n);
            break;
        case 5:
            update_gpa(&uni, n);
            break;
        default:
            break;
        }
    } while (options != 6);
    
    for (int i = 0; i < n; i++)
    {
        delete[] uni.courses[i].students;
        uni.courses[i].students = nullptr;
    }
    delete[] uni.courses;
    uni.courses = nullptr;
}
void display(const University uni, int n){
    cout<<"All Courses are the following"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-"<<endl;
        cout<<"Course Code: "<<uni.courses[i].Code<<endl;
        cout<<"Subject: "<<uni.courses[i].professor.Subject<<endl;
        cout<<"Professor Name: "<<uni.courses[i].professor.Name<<endl;
        cout<<"Professor Id: "<<uni.courses[i].professor.Id<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Students Enrolled:"<<endl;
        for (int j = 0; j < uni.courses[i].stu_count; j++)
        {
            cout<<"Name: "<<uni.courses[i].students[j].Name<<endl;
            cout<<"Roll Number: "<<uni.courses[i].students[j].Roll_num<<endl;
            cout<<"GPA: "<<uni.courses[i].students[j].Gpa<<endl;
        }
        cout<<"-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-"<<endl;
    }
}
void input_data(University* uni, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the data of Course "<<i+1<<endl;
        cout<<"Course Code: ";
        getline(cin, uni->courses[i].Code);
        cout<<"Professor: ";
        getline(cin, uni->courses[i].professor.Name);
        cout<<"ID: ";
        getline(cin, uni->courses[i].professor.Id);
        cout<<"Subject: ";
        getline(cin, uni->courses[i].professor.Subject);
        cout<<"Enter the number of students in this course: ";
        cin>>uni->courses[i].stu_count;
        cin.ignore();
        uni->courses[i].students = new Student[uni->courses[i].stu_count];
        cout<<"Students Details:"<<endl;
        for (int j = 0; j < uni->courses[i].stu_count; j++)
        {
            cout<<"Student "<<j+1<<endl;
            cout<<"Name: ";
            getline(cin, uni->courses[i].students[j].Name);
            cout<<"Roll Number: ";
            getline(cin, uni->courses[i].students[j].Roll_num);
            cout<<"GPA: ";
            cin>>uni->courses[i].students[j].Gpa;
            cin.ignore();
        }
    }
}
void enroll_stu(University* uni, int* n){
    string code;    int x, i;
    cout<<"Enter the code of the course you want to entroll students in: ";
    getline(cin, code);
    cout<<"Enter the number of students you want to enroll: ";
    cin>>x;
    cin.ignore();
    for (i = 0; i < *n; i++)
    {
        if (code == uni->courses[i].Code)
        {
            break;
        }
    }
    int new_size = uni->courses[i].stu_count + x;
    Student* stu = new Student[new_size];
    for (int j = 0; j < uni->courses[i].stu_count; j++)
    {
        stu[j] = uni->courses[i].students[j];
    }
    cout<<"Enter the data of the new students:"<<endl;
    for (int j = uni->courses[i].stu_count; j < new_size; j++)
    {
        cout<<"Name: ";
        getline(cin, stu[j].Name);
        cout<<"Roll Number: ";
        getline(cin, stu[j].Roll_num);
        cout<<"GPA: ";
        cin>>stu[j].Gpa;
    }
    
    delete[] uni->courses[i].students;
    uni->courses[i].students = stu;
    uni->courses[i].stu_count = new_size;
    stu = nullptr;
}
void update_gpa(University* uni, int n){
    string stu, code;
    cout<<"Enter the course code and roll number of the student to change gpa:"<<endl;
    getline(cin, code);
    getline(cin, stu);
    for (int i = 0; i < n; i++)
    {
        if (uni->courses[i].Code == code)
        {
            for (int j = 0; j < uni->courses[i].stu_count; j++)
            {
                if (uni->courses[i].students[j].Roll_num == stu)
                {
                    cout<<"Enter the updated gpa:";
                    cin>>uni->courses[i].students[j].Gpa;
                    cin.ignore();
                    break;
                }
            }
            break;
        }
    }
}
void remove_stu(University* uni, int* n){
    string code, roll;      int i, check=-1;
    cout<<"Enter the course code and roll number of the student you want to remove:"<<endl;
    getline(cin, code);
    getline(cin, roll);
    for (i = 0; i < *n; i++)
    {
        if (uni->courses[i].Code == code)
        {
            for (int j = 0; j < uni->courses[i].stu_count; j++)
            {
                if (uni->courses[i].students[j].Roll_num ==roll)
                {
                    check = j;
                    break;
                }
            }
            break;
        }
    }
    if (check==-1)
    {
        cout<<"Student not found!"<<endl;
        return;
    }
    for (int j = check; j < uni->courses[i].stu_count - 1; j++)
    {
        uni->courses[i].students[j] = uni->courses[i].students[j+1];
    }
    (uni->courses[i].stu_count)--;
    Student *stud = new Student[uni->courses[i].stu_count];
    for (int j = 0; j < uni->courses[i].stu_count; j++)
    {
        stud[j] = uni->courses[i].students[j];
    }
    delete[] uni->courses[i].students;
    uni->courses[i].students = stud;
    stud = nullptr;
    cout<<"The student ROll number "<<roll<<" has been removed"<<endl;
}