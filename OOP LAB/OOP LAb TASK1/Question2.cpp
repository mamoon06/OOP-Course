#include <iostream>
using namespace std;

void Display(int[], int[], int);
int main(){
    int size;
    char option;
    cout<<"Enter the size of the two arrays you want to swap: "<<endl;
    cin>>size;
    int arr1[size], arr2[size];
    cout<<"Enter the digits of the first array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the digits of the second array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr2[i];
    }
    for (int i = 0; i < size; i++)
    {
        int t = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = t;
    }
    cout<<"The arrays have been swaped!"<<endl;    
    cout<<"Do you wish to display the swaped arrays? (Y/N)"<<endl;
    cin>>option;
    if (option == 'y' || option == 'Y')
    {
        Display(arr1, arr2, size);
    }

}
void Display(int array1[], int array2[], int size){
    cout<<"Your Array 1 is the following:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl<<"Your Array 2 is the following:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<array2[i]<<" ";
    }
}