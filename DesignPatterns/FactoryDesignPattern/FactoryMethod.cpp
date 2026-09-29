#include<iostream>
#include<vector>
#include<string> 

using namespace std ; 

class Burger {
    public : 
    virtual void prepare() =0 ;
};
class BasicBurger : public Burger{
public : 
    void prepare()override{
        cout<<"this is a basic burger"<<endl;
    }
};
class BasicWheatBurger : public Burger{
public : 
    void prepare()override{
        cout<<"this is a basic wheat burger"<<endl;
    }
};

class StandardBurger : public Burger{
    public : 
    void prepare()override{
        cout<<"this is a standard burger"<<endl;
    }
};
class StandardWheatBurger : public Burger{
    public : 
    void prepare()override{
        cout<<"this is a standard wheat burger"<<endl;
    }
};

class PremiumBurger : public Burger {
    public : 
    void prepare()override{
        cout<<"this is a premium burger"<<endl;
    }
};

class PremiumWheatBurger : public Burger {
    public : 
    void prepare()override{
        cout<<"this is a premium wheat burger"<<endl;
    }
};
class BurgerFactory{
    public : 
    virtual Burger* createBurger(string type) = 0 ;
};
class SinghBurgerFactory : public BurgerFactory{
    public : 
    Burger* createBurger(string type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else {
            return new PremiumBurger();
        }
    }
};
class KingBurgerFactory : public BurgerFactory{
    public : 
    Burger* createBurger(string type){
        if(type == "basic"){
            return new BasicWheatBurger();
        }
        else if(type == "standard"){
            return new StandardWheatBurger();
        }
        else {
            return new PremiumWheatBurger();
        }
    }
};
int main(){
    BurgerFactory* Kingfactory = new KingBurgerFactory();
    Burger* burger1 = Kingfactory->createBurger("basic");
    Burger* burger2 = Kingfactory->createBurger("standard");
    Burger* burger3 = Kingfactory->createBurger("premium");
    BurgerFactory* Singhfactory = new SinghBurgerFactory();
    Burger* burger4 = Singhfactory->createBurger("basic");
    Burger* burger5 = Singhfactory->createBurger("standard");
    Burger* burger6 = Singhfactory->createBurger("premium");
    burger1->prepare();
    burger2->prepare();
    burger3->prepare();
    burger4->prepare();
    burger5->prepare();
    burger6->prepare();
    return 0 ; 
}