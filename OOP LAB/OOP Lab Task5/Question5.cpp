#include <iostream>
using namespace std;
struct Book
{
    string Title;
    string Author;
    int publicationYear;
    float Price;
};
void input_books(Book*, int);
void display_books(const Book*, int);
void most_expensive(Book*, int);
void sortby_publication(Book*, int);
int main(){
    int n, option;
    cout<<"Enter the amount of books:"<<endl;
    cin>>n;
    Book* books = new Book[n];
    input_books(books, n);
    do
    {
        cout<<"Choose an option: "<<endl;
        cout<<"(1) Display Data."<<endl<<"(2) Show Most Expensive."<<endl;
        cout<<"(3) Sort By Publication Date."<<endl;
        cout<<"(4) To End."<<endl;
        cin>>option;
        switch (option)
    {
    case 1:
        display_books(books, n);
        break;
    case 2:
        most_expensive(books, n);
    case 3:
        sortby_publication(books, n);
    default:
        break;
    }
    } while (option != 4);
    delete[] books;
    books = nullptr;
}
void input_books(Book* books, int n){
    cout<<"Enter the details of the books:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout<<"Book "<<i+1<<endl;
        cout<<"Title: ";
        getline(cin, books[i].Title);
        cout<<"Author: ";
        getline(cin, books[i].Author);
        cout<<"Publication Year: ";
        cin>>books[i].publicationYear;
        cout<<"Price: ";
        cin>>books[i].Price;
    }   
}
void display_books(const Book* books, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"Title: "<<books[i].Title<<endl;
        cout<<"Author: "<<books[i].Author<<endl;
        cout<<"Publication Year: "<<books[i].publicationYear<<endl;
        cout<<"Price: "<<books[i].Price<<endl;
        cout<<endl;
    }   
}
void most_expensive(Book* books, int n){
    float exp = books[0].Price;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (exp < books[i].Price)
        {
            exp = books[i].Price;
            index = i;
        }
    }
    cout<<"The most expensive book is the following:"<<endl;
    cout<<"Title: "<<books[index].Title<<endl;
    cout<<"Author: "<<books[index].Author<<endl;
    cout<<"Publication Year: "<<books[index].publicationYear<<endl;
    cout<<"Price: "<<books[index].Price<<endl;
}
void sortby_publication(Book* books, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i; j < n-1; j++)
        {
            if (books[j].publicationYear>books[j+1].publicationYear)
            {
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            } 
        }
    }
    
} 