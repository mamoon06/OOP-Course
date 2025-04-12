#include <iostream>
using namespace std;
int main(){
    int* ptr1 = new int;
    int* ptr2 = new int;
    cout<<"Enter the value of the first number:"<<endl;
    cin>>*ptr1;
    cout<<"Enter the value of the second number:"<<endl;
    cin>>*ptr2;
    cout<<"Before Swap:"<<endl;
    cout<<"ptr 1 = "<<*ptr1<<endl<<"ptr 2 = "<<*ptr2<<endl;
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    cout<<"After Swap:"<<endl;
    cout<<"ptr 1 = "<<*ptr1<<endl<<"ptr 2 = "<<*ptr2<<endl;
    delete ptr1;
    ptr1 = nullptr;
    delete ptr2;
    ptr2 = nullptr;
}