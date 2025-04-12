#include <iostream>
using namespace std;
struct Address
{
    string City;
    double Zip;
};
struct Company
{
    string Name;
    Address add;
    double Revenue;
};
int main(){
    Company comp[3];
    cout<<"Enter the details of the companies:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Company "<<i+1<<endl;
        cin.ignore();
        cout<<"Name: ";
        getline(cin, comp[i].Name);
        cout<<"City: ";
        getline(cin, comp[i].add.City);
        cout<<"Zip Code: ";
        cin>>comp[i].add.Zip;
        cout<<"Revenue: ";
        cin>>comp[i].Revenue;
    }
    cout<<"You entered the following details: "<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Name: "<<comp[i].Name<<endl;
        cout<<"City: "<<comp[i].add.City<<endl;
        cout<<"Zip Code: "<<comp[i].add.Zip<<endl;
        cout<<"Revenue: "<<comp[i].Revenue<<endl;
    }
    
    
}