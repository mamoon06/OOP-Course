#include <iostream>
using namespace std;
int main(){
    int row1, col1, row2, col2;
    cout<<"For Matrix 1"<<endl;
    cout<<"Number of Rows:"<<endl;
    cin>>row1;
    cout<<"Number of Coulumns:"<<endl;
    cin>>col1;
    int** matrix1 = new int*[row1];
    for (int i = 0; i < row1; i++)
    {
        matrix1[i] = new int[col1];
    }
    cout<<"Enter matrix(in rows order):"<<endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin>>matrix1[i][j];
        }
    }
    cout<<"For Matrix 2"<<endl;
    cout<<"Number of Rows:"<<endl;
    cin>>row2;
    cout<<"Number of Coulumns:"<<endl;
    cin>>col2;
    int** matrix2 = new int*[row2];
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = new int[col2];
    }
    cout<<"Enter matrix(in rows order):"<<endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin>>matrix2[i][j];
        }
    }
    if (col1 == row2)
    {
        int** ans_matrix = new int*[row1];
        for (int i = 0; i < row1; i++)
        {
            ans_matrix[i] = new int[col2]();
        }
        
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                for (int k = 0; k < col1; k++)
                {
                    ans_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        
        cout<<"The answer is:"<<endl;
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                cout<<ans_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i = 0; i < row1; i++)
        {
            delete[] ans_matrix[i];
            ans_matrix[i] = nullptr;
        }
        delete[] ans_matrix;
        ans_matrix = nullptr;
    }
    else
    {
        cerr<<"Matrices cannot be multiplied. Number of columns in 1 must be equal to number of rows in 2."<<endl;
    }
    for (int i = 0; i < row1; i++)
    {
        delete[] matrix1[i];
        matrix1[i] = nullptr;
    }
    delete[] matrix1;
    matrix1 = nullptr;
    for (int i = 0; i < row2; i++)
    {
        delete[] matrix2[i];
        matrix2[i] = nullptr;
    }
    delete[] matrix2;
    matrix2 = nullptr;
}