#include <iostream>
void array_addition(int*, int*, int);
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the arrays you want to add:"<<endl;
    cin>>size;
    int* arr1 = new int[size];
    int* arr2 = new int[size];
    cout<<"Enter the elements of the 1st array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>*(arr1 + i);
    }
    cout<<"Enter the elements of the 2st array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>*(arr2 + i);
    }
    array_addition(arr1, arr2, size);
    delete[] arr1;
    arr1 = nullptr;
    delete[] arr2;
    arr2 = nullptr;
}
void array_addition(int* ptr_1, int* ptr_2, int size){
    cout<<"Addition of the arrays:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<*(ptr_1 + i) + *(ptr_2 + i)<<" ";
    }
}