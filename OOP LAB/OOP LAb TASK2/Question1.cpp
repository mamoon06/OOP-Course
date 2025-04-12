#include <iostream>
#include <fstream>
using namespace std;
void append_age(char*);
int main(){
    char file_name[20];
    
    cout<<"Enter the file name:";
    cin>>file_name;
    cin.ignore();
    ofstream your_rollno(file_name, std::ios::out);
    if (your_rollno.is_open())
    {
        cout<<"File opened Successfully!"<<endl;
        string name, roll, hobbies;
        cout<<"Enter name:"<<endl;
        getline(cin, name);
        cout<<"Enter roll number:"<<endl;
        getline(cin, roll);
        cout<<"Enter hobbies:"<<endl;
        getline(cin, hobbies);
        your_rollno<<"Name: "<<name<<endl;
        your_rollno<<"Roll_no: "<<roll<<endl;
        your_rollno<<"Hobbies: "<<hobbies<<endl;
        your_rollno.close();
    }
    else
    {
        cerr<<"File not Opened"<<endl;
    }
    char c;
    cout<<"Do you wish to append age in your file?(y/n)"<<endl;
    cin>>c;
    if (c=='Y'||c=='y')
    {
        append_age(file_name);
    }
    
    
}
void append_age(char FileName[]){
    
    
    ofstream your_rollno(FileName, std::ios::app);
    if (your_rollno.is_open())
    {
        int age[5];
        cout<<"Enter ages:"<<endl;
        for (int i = 0; i < 5; i++)
        {
            cin>>age[i];
        }
        your_rollno<<"Ages: ";
        for (int i = 0; i < 5; i++)
        {
            your_rollno<<age[i]<<" ";
        }
        
        cout<<"File appended sucessfully"<<endl;
        your_rollno.close();
    }
    else
    {
        cerr<<"File not opened!"<<endl;
    }
    
}