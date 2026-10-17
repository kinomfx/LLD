#ifndef MENU_H
#define MENU_H 
#include<iostream>
#include<string>
#include<vector>
using namespace std ; 
class MenuItem{
    string code ; 
    string name ; 
    double price ;
    public:
    MenuItem(const string& code , const string& name , const double price){
        this->code = code ; 
        this->name = name ; 
        this->price = price;
    }
    ~MenuItem(){    
    }

    //getters and setters 
    string GetCode(){
        return this->code;
    }
    void SetCode(const string& code){
        this->code = code ; 
    }
    string GetName() const{
        return this->name;
    }
    void SetName(const string& name){
        this->name = name; 
    }
    double GetPrice() const{
        return this->price;
    }
    void SetPrice(const double price){
        this->price = price;
    }

};



#endif