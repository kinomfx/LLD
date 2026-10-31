#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<mutex>
using namespace std ; 

// Abstract Notification Class 
class INotification {
    public : 
    virtual string GetContent() = 0 ;
};

class SimpleNotification : public INotification{
    string s ; 
    public : 
    SimpleNotification(string s ){
        this->s = s ; 
    }
    string GetContent()override{
        return this->s;
    }
    void SetContent(string s ){
        this->s = s; 
    }
};

//Notification Decorator 
class INotificationDecorator : public INotification{
    public : 
    INotification* ref ; 
    INotificationDecorator(INotification* ref ){
        this->ref = ref ; 
    }
};
class TimeStampDec : public INotificationDecorator{
    string time ; 
    public : 
    TimeStampDec(string time , INotification* ref ) : INotificationDecorator(ref){
        this->time = time ; 
    }
    string GetContent()override{
        return ref->GetContent() + " Sent At : "+time;
    }
};

class SignatureDec : public INotificationDecorator{
    string name ; 
    public : 
    SignatureDec(string name , INotification* ref) : INotificationDecorator(ref){
        this->name = name ; 
    }
    string GetContent()override{
        return ref->GetContent() + " Sent By : " + name;
    }
};

// Abstract Observerable Class
class IObservers{
    public :
    virtual void Update() = 0 ;
    IObservers(){
         
    }
};
class IObeservable{
    public : 
    vector<IObservers*> observers ; 
    //CRUD ops 
    void addObserver(IObservers* obs ){
        observers.push_back(obs);
    }
    virtual void notify() = 0 ; 
};

class Observable : public IObeservable{
    public : 
    INotification* notification;
    void notify(){
        for(auto obs :  observers){
            obs->Update();
        }
    }
    INotification* GetNotification(){
        return notification ; 
    }
    void SetNotification(INotification* notification){
        this->notification = notification;
        notify();
    }
};

class NotificationLogger : public IObservers{
    public : 
    Observable* obs ; 
    NotificationLogger(Observable* obs){
        this->obs = obs ; 
    }
    void Update(){
        string content = obs->GetNotification()->GetContent();
        cout<<"Storing to file systems : "<<content<<endl;
    }
}; 

class NotificationObserver : public IObservers{
    Observable* obs ;
    public :  
    NotificationObserver(Observable* obs){
        this->obs = obs ; 
    }
    void Update()override{
        string content = obs->notification->GetContent();
        cout<<"Notification Observer Noted : "<<content<<endl;
    }   
};
class NotificationStratergy{
    public : 
    virtual void SendNotification(string content) = 0 ; 
};
class EmailStratergy : public NotificationStratergy{
    public : 
    string email ; 
    EmailStratergy(string email){
        this->email = email;
    }
    void SendNotification(string content)override{
        cout<<"Sending the Notification via mail to "<<email<<" Content : "<<content<<endl;
    }
};

class SMSStratergy : public NotificationStratergy{
    public :   
    string PhoneNumber ; 
    SMSStratergy(string PhoneNumber){
        this->PhoneNumber = PhoneNumber;
    }
    void SendNotification(string content)override{
        cout<<"Sending the Notification via SMS to "<<PhoneNumber<<" Content : "<<content<<endl;
    }

};
class NotificationEngine : public IObservers{
    public : 
    vector<NotificationStratergy*> stratergies;
    Observable* obs ; 
    void Update()override{
        string content = obs->notification->GetContent();
        for(NotificationStratergy* stratergy : stratergies){
            stratergy->SendNotification(content);
        }
    }
    void SetObservable(Observable* obs) {
        this->obs = obs ; 
    }
    void AddStratergy(NotificationStratergy* stratergy){
        stratergies.push_back(stratergy);
    }
};


// SingleTon Notification Service Class 

class NotificationService{
    static NotificationService* instance ; 
    static mutex mtx ; 
    public : 
    static NotificationService* GetInstance(){
        if(instance == NULL){
            mtx.lock();
            if(instance == NULL){
                instance = new NotificationService(); 
            }
            mtx.unlock();
        }
        return instance ; 
    }
    Observable* obs ; 
    void SendNotification(INotification* notification){
        obs->SetNotification(notification);
    }
    void SetObservable(Observable* obs){
        this->obs = obs ; 
    }
};

NotificationService* NotificationService :: instance; 
mutex NotificationService::mtx  ; 

int main(){
    NotificationService* notificationservice = NotificationService::GetInstance();
    Observable* observable = new Observable();
    notificationservice->SetObservable(observable);
    NotificationObserver* observer = new NotificationObserver(observable);
    observable->addObserver(observer);
    SimpleNotification* simplenotification = new SimpleNotification("This is a simple message");
    notificationservice->SendNotification(simplenotification);
    NotificationEngine* engine = new NotificationEngine();
    EmailStratergy* email = new EmailStratergy("Unnati1470@gmail.com");
    SMSStratergy* sms = new SMSStratergy("9811901470");
    NotificationLogger* logger = new NotificationLogger(observable);
    engine->AddStratergy(email);
    engine->AddStratergy(sms);
    engine->SetObservable(observable);
    observable->addObserver(engine);
    observable->addObserver(logger);
    INotification* secondsimplenotification = new TimeStampDec( "3:03 Pm IST" , new SignatureDec("Monik Rayu" , new SimpleNotification("This message is for all")));
    notificationservice->SendNotification(secondsimplenotification);
    return 0 ; 
}