#include <iostream>
using namespace std;
int main(){
    int days, miles;
    float cost;
    cout<<"Enter the total days of the rental: "<<endl;
    cin>>days;
    cout<<"Enter the miles driven during the rental: "<<endl;
    cin>>miles;
    if (days>30)
    {
        cost = 25.00 + (float)miles*0.15;
        cost = cost - cost*20.0/100;
    }
    else if (days<15)
    {
        cost = 25.00 + (float)miles*(0.15+1.99); 
    }
    else
    {
        cost = 25.00 + (float)miles*0.15;
    }
    
    cout<<"The total rental cost is: $"<<cost<<endl;
}