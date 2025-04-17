#include <iostream>
using namespace std;
class Book {
private:
    string Title;
    string Author;
public:
    void setDetails(string t, string a){
        Title = t;
        Author = a;
    }
    void display(){
        cout<<"Title: "<<Title<<", Author: "<<Author<<endl;
    }
};
class Library {
private:
    Book book;
public:
    void enterDetails(string title, string author){
        book.setDetails(title, author);
    }
    void display(){ book.display(); }
};
int main(){
    Library L1;
    L1.enterDetails("ABC", "Ali");
    L1.display();
}