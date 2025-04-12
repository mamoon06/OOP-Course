#include <iostream>
using namespace std;
class Person {
private:
    string name;
    int age;
public:
    Person(std::string n, int a) : name(n), age(a) {}
    void displayPersonInfo() const {
        cout<<"Name: "<<name<<", Age: "<<age<<endl;
    }
};
class Student : public Person {
private:
    char grade;
public:
    Student(std::string n, int a, char g) : Person(n, a), grade(g) {}
    void displayStudentInfo() const {
        displayPersonInfo();
        cout<<"Grade: "<<grade<<endl;
    }
};
int main() {
    Student stu("John Doe", 20, 'A');
    stu.displayStudentInfo();
}