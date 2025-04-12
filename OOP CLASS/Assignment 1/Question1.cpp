#include <iostream>
using namespace std;
void reverse_array(int[], int);
void secondlargest_element(int[], int);
void rotate_array(int[], int, int);
int main(){
    
    int size, k;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;
    int array[size];
    int* array_ptr = array;
    cout<<"Enter the array"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter the number of times you want to shift the array:"<<endl;
    cin>>k;
    cout<<"Original Array: ";
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    reverse_array(array, size);
    secondlargest_element(array, size);
    rotate_array(array, size, k);
    
}
void reverse_array(int array[], int size){
    int end = size-1;
    for (int i = 0; i < end; i++)
    {
        int temp = *(array+i);
        *(array+i) = *(array+end);
        *(array+end) = temp;
        end--;
    }
    cout<<"Reversed Array: ";
    for (int i = 0; i < size; i++)
    {
        cout<<*(array+i)<<" ";
    }
    cout<<endl;
}
void secondlargest_element(int array[], int size){
    int largest = *(array);
    int second_largest = *(array+1);
    for (int i = 0; i < size; i++)
    {
        if (*(array+i)>largest)
        {
            largest=*(array+i);
        }
        if (*(array+i)<largest && *(array+i)>second_largest)
        {
            second_largest = *(array+i);
        }
    }
    cout<<"Second Largest: "<<second_largest<<endl;
}
void rotate_array(int array[], int size, int k){
    k = k % size;
    if (k == 0)
    {
        cout<<"Rotated Array: ";
        for (int i = 0; i < size; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = array[size - k + i];
    }
    for (int i = size - 1; i >= k; i--)
    {
        array[i] = array[i - k];
    }
    for (int i = 0; i < k; i++)
    {
        array[i] = temp[i];
    }
    cout<<"Rotated Array: ";
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}