#include <iostream>
using namespace std;
struct Doctor
{
    string Name;
    string Specialization;
};
struct Hospital
{
    string Name;
    Doctor d1, d2, d3;
};
void display_detail(Hospital*, int);
int main(){
    int n;
    cout<<"Enter the number of hospitals:"<<endl;
    cin>>n;
    Hospital* hospitals = new Hospital[n];
    cout<<"Enter the details of the Hospitals:"<<endl;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout<<"Hospital "<<i+1<<endl;
        cout<<"Hospital Name: ";
        getline(cin, hospitals[i].Name);
        cout<<"Doctor 1 Name:";
        getline(cin, hospitals[i].d1.Name);
        cout<<"Doctor 1 Specialization: ";
        getline(cin, hospitals[i].d1.Specialization);
        cout<<"Doctor 2 Name:";
        getline(cin, hospitals[i].d2.Name);
        cout<<"Doctor 2 Specialization: ";
        getline(cin, hospitals[i].d2.Specialization);
        cout<<"Doctor 3 Name:";
        getline(cin, hospitals[i].d3.Name);
        cout<<"Doctor 3 Specialization: ";
        getline(cin, hospitals[i].d3.Specialization);
    }

    display_detail(hospitals, n);
    delete[] hospitals;
    hospitals = nullptr;
}
void display_detail(Hospital* h, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<endl;
        cout<<"Hospital: "<<h[i].Name<<endl;
        cout<<"Dr. "<<h[i].d1.Name<<" ("<<h[i].d1.Specialization<<")"<<endl;
        cout<<"Dr. "<<h[i].d2.Name<<" ("<<h[i].d2.Specialization<<")"<<endl;
        cout<<"Dr. "<<h[i].d3.Name<<" ("<<h[i].d3.Specialization<<")"<<endl;
    }
    
}