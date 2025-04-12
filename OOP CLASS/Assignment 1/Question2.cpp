#include <iostream>
using namespace std;
void display_matrix(int **, int);
int diagonal_sum(int**, int);
int absolute_diagonal_difference(int**, int);
int main(){
    int n, nums=1;
    cout<<"Enter the size of the matrix:"<<endl;
    cin>>n;
    int** Matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        Matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix[i][j] = nums;
            nums++;
        }
    }
    display_matrix(Matrix, n);
    cout<<"Sum of Main Diagonal = "<<diagonal_sum(Matrix, n)<<endl;
    cout<<"Absolute Difference of Diagonals = "<<absolute_diagonal_difference(Matrix, n)<<endl;
    for (int i = 0; i < n; i++)
    {
        delete[] Matrix[i];
        Matrix[i] = nullptr;
    }
    delete[] Matrix;
    Matrix = nullptr;
}
void display_matrix(int** matrix, int size){
    cout<<"Matrix"<<endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int diagonal_sum(int** matrix, int size){
    int sum = 0;
    for (int i=0, j=0; i < size; i++, j++)
    {
        sum += matrix[i][j];
    }
    return sum;
}
int absolute_diagonal_difference(int** matrix, int size){
    int d_sum = diagonal_sum(matrix, size), sd_sum=0;
    int difference;
    for (int i=0, j=size-1; i < size; i++, j--)
    {
        sd_sum += matrix[i][j];
    }
    difference = d_sum - sd_sum;
    if (difference<0)
    {
        difference = -difference;
    }
    return difference;
}