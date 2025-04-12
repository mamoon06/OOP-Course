#include <iostream>
void resize_array(int*, int*, int, int);
using namespace std;
int main(){
    int d_size, b_size;
    cout<<"Enter the size of the dynamic array:"<<endl;
    cin>>d_size;
    cout<<"Enter the size of the bigger array:"<<endl;
    cin>>b_size;
    int* arr = new int[d_size];
    int array[b_size];
    cout<<"Enter the elements of the array:"<<endl;
    for (int i = 0; i < d_size; i++)
    {
        cin>>*(arr + i);
    }
    resize_array(arr, array, d_size, b_size);
    delete[] arr;
    arr = nullptr;
}
void resize_array(int* d_array, int* b_array, int d_size, int b_size){
    for (int i = 0; i < d_size; i++)
    {
        *(b_array+i) = *(d_array + i);
    }
    for (int i = 0; i < b_size; i++)
    {
        cout<<*(b_array+i)<<" ";
    }
}