#include <iostream>
using namespace std;
class CoffeeOrder{
public:
    void processOrder(int size, int price){
        cout<<"Total Cost: Rs."<<(size * price)<<endl;
    }
};
class CustomOrder : public CoffeeOrder{
public:
    void processOrder(int size, int price){
        cout<<"Welcome to our Coffee Shop! Here's your order summary:"<<endl;
        CoffeeOrder::processOrder(size, price);
    }
};
int main() {
    int size, price;
    cout << "Enter drink size (in ounces): ";
    cin >> size;
    cout << "Enter price per ounce: ";
    cin >> price;
    
    CoffeeOrder standardOrder;
    cout << "\nProcessing Standard Order:" << endl;
    standardOrder.processOrder(size, price);
    
    CustomOrder specialOrder;
    cout << "\nProcessing Custom Order:" << endl;
    specialOrder.processOrder(size, price);
}