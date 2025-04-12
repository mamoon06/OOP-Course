#include <iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;
    int* ptr = new int[size];
    cout<<"Enter the elements of the array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>*(ptr+i);
    }
    int end = size-1;
    for (int i = 0; i < end; i++)
    {
        int temp = *(ptr+i);
        *(ptr+i) = *(ptr+end);
        *(ptr+end) = temp;
        end--;
    }
    cout<<"Reverse Array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<*(ptr+i)<<" ";
    }
    delete[] ptr;
    ptr = nullptr;
}