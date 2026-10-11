#include<iostream>
#include<vector>
#include<string> 
using namespace std ; 

class A{
    private : 
        A(){
            cout<<"this is a private constructor"<<endl;
        }
       static A* instance ; 
    public : 
        static A* getInstance(){
            return instance;
        }
};

A* A::instance = new A() ; //eager initialization

int main(){
    A* a1 = A::getInstance();
    A* a2 = A::getInstance();
    if(a1 == a2){
        cout<<"both are same instance"<<endl;
    }
    else {
        cout<<"both are different instance"<<endl;
    }
    return 0 ; 

}