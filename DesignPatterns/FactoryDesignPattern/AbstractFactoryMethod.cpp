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
class GarlicBread {
    public : 
    virtual void prepare() =0 ;
};
class BasicGarlicBread : public GarlicBread{
public : 
    void prepare()override{
        cout<<"this is a basic GarlicBread"<<endl;
    }
};
class BasicWheatGarlicBread : public GarlicBread{
public : 
    void prepare()override{
        cout<<"this is a basic wheat GarlicBread"<<endl;
    }
};

class StandardGarlicBread : public GarlicBread{
    public : 
    void prepare()override{
        cout<<"this is a standard GarlicBread"<<endl;
    }
};
class StandardWheatGarlicBread : public GarlicBread{
    public : 
    void prepare()override{
        cout<<"this is a standard wheat GarlicBread"<<endl;
    }
};

class PremiumGarlicBread : public GarlicBread {
    public : 
    void prepare()override{
        cout<<"this is a premium GarlicBread"<<endl;
    }
};

class PremiumWheatGarlicBread : public GarlicBread {
    public : 
    void prepare()override{
        cout<<"this is a premium wheat GarlicBread"<<endl;
    }
};
class Factory{
    public : 
    virtual Burger* createBurger(string type) = 0 ;
    virtual GarlicBread* createGarlicBread(string type) = 0 ; 
};
class SinghBurgerFactory : public Factory{
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
    GarlicBread* createGarlicBread(string type){
        if(type == "basic"){
            return new BasicGarlicBread();
        }
        else if(type == "standard"){
            return new StandardGarlicBread();
        }
        else {
            return new PremiumGarlicBread();
        }
    }
};
class KingBurgerFactory : public Factory{
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
    GarlicBread* createGarlicBread(string type){
        if(type == "basic"){
            return new BasicWheatGarlicBread();
        }
        else if(type == "standard"){
            return new StandardWheatGarlicBread();
        }
        else {
            return new PremiumWheatGarlicBread();
        }
    }
};
int main(){
    Factory* Kingfactory = new KingBurgerFactory();
    Burger* burger1 = Kingfactory->createBurger("basic");
    Burger* burger2 = Kingfactory->createBurger("standard");
    Burger* burger3 = Kingfactory->createBurger("premium");
    Factory* Singhfactory = new SinghBurgerFactory();
    Burger* burger4 = Singhfactory->createBurger("basic");
    Burger* burger5 = Singhfactory->createBurger("standard");
    Burger* burger6 = Singhfactory->createBurger("premium");
    GarlicBread* garlicbread1 = Kingfactory->createGarlicBread("basic");
    GarlicBread* garlicbread2 = Kingfactory->createGarlicBread("standard");
    GarlicBread* garlicbread3 = Kingfactory->createGarlicBread("premium");
    GarlicBread* garlicbread4 = Singhfactory->createGarlicBread("basic");
    GarlicBread* garlicbread5 = Singhfactory->createGarlicBread("standard");
    GarlicBread* garlicbread6 = Singhfactory->createGarlicBread("premium");
    burger1->prepare();
    burger2->prepare();
    burger3->prepare();
    garlicbread1->prepare();
    garlicbread2->prepare();
    garlicbread3->prepare();
    burger4->prepare();
    burger5->prepare();
    burger6->prepare();
    garlicbread4->prepare();
    garlicbread5->prepare();
    garlicbread6->prepare();
    return 0 ; 
}