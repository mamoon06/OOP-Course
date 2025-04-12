#include<iostream>
#include<string>
using namespace std;
int main(){
    char* string1 = new char[25];
    char* string2 = new char[25];
    cout<<"Enter the first string:"<<endl;
    cin.getline(string1, 25);
    cout<<"Enter the second string:"<<endl;
    cin.getline(string2, 25);
    int length1=0, length2=0, i=0, flage=0;
    while (*(string1+i) != '\0')
    {
        length1++;
        i++;
    }
    i = 0;
    while (*(string2+i) != '\0')
    {
        length2++;
        i++;
    }
    if (length1 == length2)
    {
        for (i = 0; i <= length1; i++)
        {
            if (*(string1+i) != *(string1+length2))
            {
                flage++;
                break;
            }
            length2--;
        } 
    }
    else
    {
        cout<<"The string are NOT reverse!"<<endl;
    }
    if (flage == 0)
    {
        cout<<"The strings are reverse!"<<endl;
    }
    else
    {
        cout<<"The strings are NOT reverse!"<<endl;
    }
    delete string1;
    string1 = nullptr;
    delete string2;
    string2 = nullptr;
}