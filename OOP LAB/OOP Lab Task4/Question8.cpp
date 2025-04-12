#include <iostream>
using namespace std;
struct Book
{
    string title;
    string author;
    int pages;
    float price;
};
int main(){
    Book b1;
    cout<<"Enter the title of the book"<<endl;
    getline(cin, b1.title);
    cout<<"Enter the author of the book"<<endl;
    getline(cin, b1.author);
    cout<<"Enter the number of pages in the book"<<endl;
    cin>>b1.pages;
    cout<<"Enter the price of the book"<<endl;
    cin>>b1.price;
    cout<<"You entered the following book:"<<endl;
    cout<<"Title: "<<b1.title<<endl;
    cout<<"Author: "<<b1.author<<endl;
    cout<<"Pages: "<<b1.pages<<endl;
    cout<<"Price: Rs. "<<b1.price<<endl;
}