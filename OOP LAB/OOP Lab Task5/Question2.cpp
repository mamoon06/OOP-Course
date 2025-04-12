#include <iostream>
using namespace std;
struct Book
{
    string Title;
    string Author;
    float Price;
};

int main(){
    Book books[5] = {{"Treasure Island", "Robert Louis Stevenson", 1000}, {"David Copperfield", "Charles Dickens", 600}, {"Great Expectations", "Charles Dickens", 165}, {"Dracula", "Bram Stoker", 450.65}, {"War and Peace", "Leo Tolstoy", 510.99}};
    for (int i = 0; i < 5; i++)
    {
        if (books[i].Price>500)
        {
            cout<<"Title: "<<books[i].Title<<endl;
            cout<<"Author: "<<books[i].Author<<endl;
            cout<<"Price: $"<<books[i].Price<<endl;
            cout<<"-/-/-/-/-/-/-/-/-/-/-/-/-/"<<endl;
        }   
    }
}