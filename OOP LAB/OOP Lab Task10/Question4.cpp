#include <iostream>
#include <algorithm>
using namespace std;
class Encryptor;
class Message {
private:
    string content;
public:
    Message(string c) : content(c){}
    friend class Encryptor;
};
class Encryptor {
public:
    void encrypt(Message m){
       reverse(m.content.begin(), m.content.end());
    cout<<"Encrypted Message: "<<m.content<<endl;
    }
};
int main(){
    Message m("Hey there! How are you?");
    Encryptor enct;
    enct.encrypt(m);
}