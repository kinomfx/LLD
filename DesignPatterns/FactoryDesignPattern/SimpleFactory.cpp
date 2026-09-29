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

class StandardBurger : public Burger{
    public : 
    void prepare()override{
        cout<<"this is a standard burger"<<endl;
    }
};

class PremiumBurger : public Burger {
    public : 
    void prepare()override{
        cout<<"this is a premium burger"<<endl;
    }
};

class BurgerFactory{
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
int main(){
    BurgerFactory* factory = new BurgerFactory();
    Burger* burger1 = factory->createBurger("basic");
    Burger* burger2 = factory->createBurger("standard");
    Burger* burger3 = factory->createBurger("premium");
    burger1->prepare();
    burger2->prepare();
    burger3->prepare();
    return 0 ; 
}