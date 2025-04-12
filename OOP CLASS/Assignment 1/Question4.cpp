#include <iostream>
using namespace std;
int sum_array(int[], int);
int factorial(int);
int main(){
    int array[5], n;
    cout<<"Enter the elements of the array:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin>>array[i];
    }
    cout<<"Sum of the array = "<<sum_array(array, 5)<<endl;
    cout<<"Now enter a number to find factorial:"<<endl;
    cin>>n;
    cout<<"Factorial = "<<factorial(n)<<endl;
}
int sum_array(int array[], int size){
    if (size <= 0)
    {
        return 0;
    }
    return array[size-1] + sum_array(array, size-1);
}
int factorial(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n*factorial(n-1);
}