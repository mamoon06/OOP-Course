#include <iostream>
using namespace std;
class Logger
{
private:
    static string Logs[10];
    static int Count;
public:
    void log(string msg){
        if (Count<10)
        {
            Logs[Count] = msg;
            cout<<"Message stored successfully!"<<endl;
            Count++;
        }
        else{ cout<<"Error Log is full!!"<<endl;    }
    }
    void printlog(){
        for (int i = 0; i < Count; i++)
        {   cout<<Logs[i]<<endl;      }  
    }
};
string Logger::Logs[10];
int Logger::Count=0;
int main(){
    Logger logg;
    logg.log("Hi there!");
    logg.log("Greetings People of EARTH");
    logg.log("Kaizoku ni! Ore wa Naru!!");
    logg.printlog();
}