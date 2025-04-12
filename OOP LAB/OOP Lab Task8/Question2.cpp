#include <iostream>
using namespace std;
class Device
{
protected:
    string Name;
    bool PowerStatus;
    string Location;
public:
    Device(string name, string loc) : Name(name), Location(loc), PowerStatus(false){}
    void turnON(){ PowerStatus = true;  cout<<Name<<" is ON!"<<endl; }
    void turnOFF(){ PowerStatus = false;    cout<<Name<<" is OFF!"<<endl; }
    void showStatus(){ cout<<(PowerStatus ? "ON" : "OFF")<<endl; }
};
class SmartLight : public Device
{
protected:
    int Brightness;
    string Color;
public:
    SmartLight(string name, string loc) : Device(name, loc), Brightness(100), Color("White"){}
    void adjustBrightness(int level){
        if (level<0)
        {
            Brightness = 0;
        }else if (level>100)
        {
            Brightness = 100;
        }else{
            Brightness = level;
        }        
    }
    void changeColor(string newColor){
        Color = newColor;
    }
};
class SmartThermostat : public Device
{
protected:
    float Temperature;
    string Mode;
public:
    SmartThermostat(string name, string loc) : Device(name, loc), Temperature(22.00), Mode("Auto"){}
    void setTemp(float temp){
        Temperature =temp;
        cout<<"Temperature Changed!"<<endl;
    }
    void switchMode(string newMode){
        Mode = newMode;
    }
};
class SmartSecurityCamera : public Device
{
protected:
    string Resolution;
    bool RecordingStatus;
public:
    SmartSecurityCamera(string name, string loc) : Device(name, loc), Resolution("1084p"), RecordingStatus(false){}
    void startRecoding(){ RecordingStatus = true; }
    void stopRecording(){ RecordingStatus = false; }
    void viewFeed(){ cout<<"You are viewing live feed in "<<Resolution<<" resolution."<<endl; }
};
int main(){
    
}