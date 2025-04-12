#include <iostream>
using namespace std;
int main(){
    int size, count=0, common=0;
    cout<<"Enter the size of both the arrays:"<<endl;
    cin>>size;
    int arr1[size], arr2[size];
    cout<<"Enter the elements of the 1st array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the elements of the 2st array:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr2[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (arr1[i]==arr2[i])
        {
            count++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr1[i]==arr2[j])
            {
                common++;
            }
        }
    }
    cout<<"There are "<<count<<" integers that are at the same place for both the arrays"<<endl;
    cout<<"There are "<<common<<" common integer in the arrays."<<endl;
}