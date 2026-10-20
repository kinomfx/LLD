#include<iostream>
#include<string>
#include<vector>
using namespace std ; 
class ISubscriber{
public : 
    virtual void update() = 0 ; 
};

class IChannel{
public : 
    
    virtual void add(ISubscriber* sub) = 0 ; 
    virtual void remove(ISubscriber* sub) = 0 ; 
    virtual void notify() = 0; 
};


class Channel : public IChannel {
    public : 
    vector<ISubscriber*> Subs;
    string name ; 
    int sub_count; 
    Channel(string name){
        this->name = name ; 
        this->sub_count = 0 ; 
        this->Subs = {};
    }
    void add(ISubscriber* sub){
        Subs.push_back(sub);
        sub_count++;
        notify();
    }
    void remove(ISubscriber* sub){
        int idx = 0 ; 
        for(idx ; idx < Subs.size() ; idx++){
            if(Subs[idx] == sub){
                break;
            }
        }
        if(idx < Subs.size()) Subs.erase(Subs.begin() + idx);
        sub_count--;
        notify();
    }
    void notify(){
        for(auto Sub : Subs){
            Sub->update();
        }
    }
    int getSubs(){
        return this->sub_count;
    }
};


class Subscriber : public ISubscriber{
    public : 
    Channel* channel ; 
    string name ; 
    Subscriber(Channel* channel , string name ){
        this->channel = channel;
        this->name = name ; 
    }
    void update(){
        cout<<"The sub count for channel : "<<channel->name<< " changed to  : "<<channel->getSubs()<<" for "<<this->name<<endl;
    }
};

int main(){
    Channel* PewDiePie = new Channel("PewDiePie");
    Subscriber* monik = new Subscriber(PewDiePie , "monik");
    Subscriber* random = new Subscriber(PewDiePie, "random");
    PewDiePie->add(monik);
    PewDiePie->add(random);
    return 0 ; 
}