#include<iostream>
#include<vector> 
#include<string>
using namespace std ; 


class Walk{
    public : 
    virtual void walk() = 0 ; 
};
class Talk{
    public : 
    virtual void talk() = 0 ; 
};
class Fly{
    public : 
    virtual void fly() = 0 ;
};


class NormalWalk : public Walk {
    public: 
    void walk(){
        cout<<"This is a normal walk"<<endl;
    }
};
class NoWalk : public Walk {
    public : 
    void walk(){
        cout<<"this is no walk "<<endl;
    }
};  

class NormalTalk : public Talk{
    public : 
    void talk(){
        cout<<"this is normal Talk"<<endl;
    }
};

class NoTalk : public Talk{
    public : 
    void talk(){
        cout<<"This is no talk"<<endl;
    }
};


class NormalFly : public Fly{
    public : 
    void fly(){
        cout<<"this is normal fly"<<endl;
    }
};

class NoFly : public Fly{
    public : 
    void fly(){
        cout<<"this is no fly"<<endl;
    }
};



class Robot{
    private : 
    Walk* walk ; 
    Talk* talk ; 
    Fly* fly ; 
    public  :
    Robot(Walk* walk , Talk* talk , Fly* fly){
        this->walk = walk ; 
        this->talk = talk ; 
        this->fly = fly ; 
    }
    void Walk1(){
        walk->walk();
    }
    void Talk1(){
        talk->talk();
    }
    void Fly1(){
        fly->fly();
    }
    virtual void Projection() = 0 ;     
};

class CompanionRobot : public Robot{
    public : 
        CompanionRobot(Walk* walk , Talk* talk , Fly* fly):Robot(walk , talk , fly){}
        void Projection() override{
            cout<<"this is a companion Robot"<<endl;
        }
};      



int main(){
    Robot* comp1  = new CompanionRobot(new NormalWalk() , new NormalTalk() , new NoFly());
    comp1->Walk1();
    comp1->Talk1();
    comp1->Fly1();
    cout<<"----------------------------"<<endl;
    Robot* comp2 = new CompanionRobot(new NoWalk() , new NormalTalk() , new NormalFly());
    
    comp2->Walk1();
    comp2->Talk1();
    comp2->Fly1();
}