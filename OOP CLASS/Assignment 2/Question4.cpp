#include <iostream>
using namespace std;
class Book{
public:
    string Title;
    string Author;    
};
int main(){
    Book *book = new Book;
    book->Title = "Calculus";
    book->Author = "Shams Ul Arefeen";
    cout<<"Book Title: "<<book->Title<<endl;
    cout<<"Book Author: "<<book->Author<<endl;
    delete book;
    book = nullptr;
}