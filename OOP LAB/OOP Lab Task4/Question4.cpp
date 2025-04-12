#include <iostream>
using namespace std;
void transpose_matrix(int*[], int, int);
int main(){
    int rows, cols;
    cout<<"Enter the number of rows of the matrix:"<<endl;
    cin>>rows;
    cout<<"Enter the number of columns:"<<endl;
    cin>>cols;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        *(matrix+i) = new int[cols];
    }
    cout<<"Enter the matrix in the order of rows:"<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin>>*(*(matrix + i)+ j);
        }
    }
    transpose_matrix(matrix, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}
void transpose_matrix(int* matrix[], int rows, int cols){

    int transpose[cols][rows];
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            *(*(transpose + i)+j) = *(*(matrix+j)+i);
        }
    }
    cout<<"Transpose of the matrix:"<<endl;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }    
}