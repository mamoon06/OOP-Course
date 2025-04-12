#include<iostream>
using namespace std;
int main(){
    int array[25];
    int j = 0;
   for (int i = 0; 1; i++)
    {
        int test, flag = 0;
        cout<<"Enter a number between 10 and 100"<<endl;
        cin>>test;
        for (int k = 0; k < j; k++)
        {
            if (array[k]==test)
            {
                flag++;
            }
            
        }
        
        if (test >= 10 && test <= 100 && flag==0)
        {
            array[j] = test;
            j++;
        }
        else
        {
           cout<<"INVALID INPUT"<<endl;
        }
        if (j==24)
        {
            break;
        }
        
    }
    cout<<"You entered the following numbers: "<<endl;
    for (int i = 0; i < 25; i++)
    {
        cout<<array[i]<<" ";
    }
    
}