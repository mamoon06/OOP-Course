#include <iostream>
using namespace std;
int main(){
    int rows, count=0;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
    char** arr = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new char[20];
    }
    for (int i = 0; i < rows; i++)
    {
        cout<<"Enter the word in row "<<i+1<<endl;
        cin>>arr[i];
    }
    for (int i = 0; i < rows-1; i++)
    {
        if ((i+1)%2==0)
        {
            continue;
        }
        else
        {
            char temp = arr[i][0];
            arr[i][0] = arr[i+1][0];
            arr[i+1][0] = temp;
        }
    }
    cout<<"The revised 2D array is the following:"<<endl;
    for (int i = 0; i < rows; i++)
    {
        int j=0;
        while (arr[i][j] != '\0')
        {
            count++;
            cout<<arr[i][j];
            j++;
        }
        cout<<endl;
    }
    cout<<"The 2D array has "<<count<<" characters!"<<endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;
}
