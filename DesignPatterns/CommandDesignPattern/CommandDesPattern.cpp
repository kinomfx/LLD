#include<iostream>
#include<vector>
#include<string> 
using namespace std ; 

class Light{
    public : 
    void On(){
        cout<<"The Light has been turned ON "<<endl;
    }
    void Off(){
        cout<<"The Light has been turned OFF"<<endl;
    }
};
class Fan{
    public : 
    void On(){
        cout<<"The Fan has been turned ON"<<endl;
    }
    void Off(){
        cout<<"The Fan has been turned OFF"<<endl;
    }
};
class AC{
    public : 
    void On(){
        cout<<"The AC has been turned ON"<<endl;
    }
    void Off(){
        cout<<"The AC has been turned OFF"<<endl;
    }
};

class ICommand{
    public : 
    virtual void Execute() = 0 ; 
    virtual void Undo() = 0 ; 
};
class LightCommand : public ICommand{
    public : 
    Light* light ; 
    LightCommand(Light* light){
        this->light = light ; 
    }
    void Execute(){
        light->On();
    }
    void Undo(){
        light->Off();
    }
    
};
class FanCommand : public ICommand{
    public : 
    Fan* fan ; 
    void Execute(){
        fan->On();
    }
    void Undo(){
        fan->Off();
    }
    FanCommand(Fan* fan){
        this->fan = fan; 
    }
};

class ACCommand : public ICommand{
    public : 
    AC* ac ; 
    void Execute(){
        ac->On();
    }
    void Undo(){
        ac->Off();
    }
    ACCommand(AC* ac){
        this->ac = ac ; 
    }
};

class Remote{
    public : 
    int const static Buttons = 4 ; 

    ICommand* buttons[Buttons];
    bool buttonPressed[Buttons];
    Remote(){
        for(int i = 0 ; i < Buttons ; i++){
            buttons[i] = nullptr;
            buttonPressed[i] = false;
        }
    }
    void PressButton(int idx){
        if(idx > 4 || idx < 0) {
            return ; 
        }
        if(buttons[idx] == nullptr){
            return ; 
        }
        if(buttonPressed[idx]){
            buttons[idx]->Undo();
            buttonPressed[idx] = false ; 
        }else{
            buttons[idx]->Execute();
            buttonPressed[idx] = true ; 
        }
    }
    void SetCommand(ICommand* command , int button){
        if(button > 4 || button < 0) {
            return ; 
        }
        buttons[button] = command; 
        buttonPressed[button] = false; 
    }
};


int main(){
    Remote* remote = new Remote();
    Light* light = new Light();
    ICommand* lightcommand = new LightCommand(light);
    Fan* fan = new Fan();
    ICommand* fancommand = new FanCommand(fan);
    AC* ac = new AC();
    ICommand* accommand = new ACCommand(ac);
    remote->SetCommand(lightcommand , 0);
    remote->SetCommand(fancommand , 1);
    remote->SetCommand(accommand , 2);
    remote->PressButton(0);
    remote->PressButton(1);
    remote->PressButton(0);
    remote->PressButton(1);
    remote->PressButton(2);
    remote->PressButton(2);
    remote->PressButton(1);    
}