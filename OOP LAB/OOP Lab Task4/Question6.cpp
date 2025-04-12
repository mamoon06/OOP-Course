#include <iostream>
using namespace std;
int main(){
    int** seats = new int*[10];
    for (int i = 0; i < 10; i++)
    {
        seats[i] = new int[10]();
    }
    int reserved_seats=0;
    char option;
    do
    {
        int row, col;
        cout<<"Enter the the row of the seat (0 to 9) and seat number (0 to 9)"<<endl;
        cin>>row>>col;
        if ((row>=0 && row<10) && (col>=0 && col<10))
        {
            if (seats[row][col] == 0)
            {
                seats[row][col] = 1;
                reserved_seats++;
                cout<<"Seat has been reserved!"<<endl;
            }
            else
            {
                cout<<"Seat is already reserved please select another seat!"<<endl;
            }
        }
        else
        {
            cout<<"Invalid seat number or Row!"<<endl;
        }
        cout<<"To continue reserving type 'y' else type 'n'"<<endl;
        cin>>option;
    } while (option == 'y' || option == 'Y');
    cout<<"The total number of reserve seats are: "<<reserved_seats<<endl;
    for (int i = 0; i < 10; i++)
    {
        delete[] seats[i];
        seats[i] = nullptr;
    }
    delete[] seats;
    seats = nullptr;
}