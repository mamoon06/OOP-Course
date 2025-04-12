#include <iostream>
using namespace std;
struct Doctor
{
    string Name;
    string Specs;
};
struct Patient
{
    string Name;
    string Checkup_date;
    Doctor doctor;
};
struct Hospital
{
    string Name;
    Patient* patient;
};
void admit_patient(Hospital*, int*);
void display_patients(Hospital*, int*);
void discharge_patient(Hospital*, int*);
int main(){
    Hospital hospital;
    int n, options;
    cout<<"Enter the number of patients:"<<endl;
    cin>>n;
    cin.ignore();
    hospital.patient = new Patient[n];
    cout<<"Enter Details:"<<endl;
    cout<<"Hospital Name: ";
    getline(cin, hospital.Name);
    for (int i = 0; i < n; i++)
    {
        cout<<"For Patient "<<i+1<<endl;
        cout<<"Name: ";
        getline(cin, hospital.patient[i].Name);
        cout<<"Checkup Date: ";
        getline(cin, hospital.patient[i].Checkup_date);
        cout<<"Doctor Name: ";
        getline(cin, hospital.patient[i].doctor.Name);
        cout<<"Specialization: ";
        getline(cin, hospital.patient[i].doctor.Specs);
    }
    do
    {
        cout<<"Choose One of the Operation You Want to Perform: "<<endl;
        cout<<"(1) Display All the Patients!"<<endl<<"(2) Admit New Patient/s!"<<endl;
        cout<<"(3) Discharge A Patient!"<<endl<<"(4) End the Program!"<<endl;
        cin>>options;
        cin.ignore();
        switch (options)
        {
        case 1:
            display_patients(&hospital, &n);
            break;
        case 2:
            admit_patient(&hospital, &n);
            break;
        case 3:
            discharge_patient(&hospital, &n);
            break;
        default:
            break;
        }
    } while (options!=4);
    delete[] hospital.patient;
    hospital.patient = nullptr;
}
void display_patients(Hospital* h, int* n){
    cout<<"The hospital has the following patients:"<<endl;
    for (int i = 0; i < *n; i++)
    {
        cout<<"Name: "<<h->patient[i].Name<<endl;
        cout<<"Assigned Doctor:"<<endl;
        cout<<"Dr. "<<h->patient[i].doctor.Name<<endl;
        cout<<"("<<h->patient[i].doctor.Specs<<")"<<endl;
        cout<<"Checkup Date: "<<h->patient[i].Checkup_date<<endl;
        cout<<endl;
    }
    
}
void admit_patient(Hospital* h, int* n){
    int x;
    cout<<"How many patients do you want to admit:"<<endl;
    cin>>x;
    int new_size = *n + x;
    Patient* new_patient = new Patient[new_size];
    for (int i = 0; i < *n; i++)
    {
        new_patient[i] = h->patient[i];
    }
    cin.ignore();
    cout<<"Enter the details of the new patients:"<<endl;
    for (int i = *n; i < new_size; i++)
    {
        cout<<"Patient Name: ";
        getline(cin, new_patient[i].Name);
        cout<<"Checkup Date: ";
        getline(cin, new_patient[i].Checkup_date);
        cout<<"Doctor Name: ";
        getline(cin, new_patient[i].doctor.Name);
        cout<<"Specialization: ";
        getline(cin, new_patient[i].doctor.Specs);
    }
    delete h->patient;
    h->patient = new_patient;
    *n = new_size;    
}
void discharge_patient(Hospital* h, int* n){
    string name;
    int check=-1;
    cout<<"Enter the name of the patient you want to discharge:"<<endl;
    getline(cin, name);
    for (int i = 0; i < *n; i++)
    {
        if (h->patient[i].Name == name)
        {
            check = i;
            break;
        }
    }
    if (check==-1)
    {
        cout<<"Patient not found!"<<endl;
        return;
    }
    
    for (int i = check; i < *n-1; i++)
    {
        h->patient[i] = h->patient[i+1];
    }
    (*n)--;
    Patient* new_patient = new Patient[*n];
    for (int i = 0; i < *n; i++)
    {
        new_patient[i] = h->patient[i];
    }
    delete[] h->patient;
    h->patient = new_patient;

    cout<<"The Patient "<<name<<" has been discharged!"<<endl;
}