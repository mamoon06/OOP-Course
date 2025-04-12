#include <iostream>
#include <string>
using namespace std;
int main(){
    char str1[50], str2[50];
    int strlen1=0, strlen2=0, i=0, flag=0;
    cout<<"Enter the first string:"<<endl;
    cin.getline(str1, 50);
    cout<<"Enter the second string:"<<endl;
    cin.getline(str2, 50);
    while (str1[i]!='\0')
    {
        strlen1++;
        i++;
    }
    i=0;
    while (str2[i]!='\0')
    {
        strlen2++;
        i++;
    }
    if (strlen1==strlen2)
    {
        for (i = 0; i < strlen1-1; i++, strlen2--)
        {
            if (str1[i]!=str2[strlen2-1])
            {
                flag++;
                break;
            }
        }
        if (flag==0)
        {
            cout<<"Strings are reverse of each other!"<<endl;
        }
        else
        {
            cout<<"Strings are NOT reverse of each other!"<<endl;
        }
    }
    else
    {
        cout<<"Strings are NOT reverse of each other!"<<endl;
    }


}