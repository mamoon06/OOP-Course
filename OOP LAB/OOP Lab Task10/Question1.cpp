#include <iostream>
using namespace std;
class BankAccount {
private:
    double Balance;
public:
    BankAccount(double b) : Balance(b){}
    friend void displayBalance(BankAccount);
};
void displayBalance(BankAccount acc){
    cout<<"Balance: $"<<acc.Balance<<endl;
}
int main(){
    BankAccount b1(100000), b2(50000);
    displayBalance(b1);
    displayBalance(b2);
}