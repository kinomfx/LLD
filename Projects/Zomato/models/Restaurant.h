#ifndef RESTARUNT_H
#define RESTARUNT_H
#include<string> 
#include<vector>
#include<iostream>
#include "MenuItem.h"
using namespace std ; 

class Restaurant{
private :
    static int NextRestrauntId ;
    int id ; 
    vector<MenuItem> menu ; 
    string name ; 
    string addr ; 
public:
    Restaurant(const string& name , const string& addr){
        this->name = name ;
        this->addr = addr ; 
        this->id = NextRestrauntId++ ;
    }

    ~Restaurant(){
        cout<<"Restraunt Destructor called for Restraunt : "<<this->name<<endl ;
    }
    //getters and setters 
    string GetName() const{
        return name;
    }
    void setName(const string& name){
        this->name = name ; 
    }
    string getLoc() const{
        return addr;
    }
    void setLoc(const string& addr){
        this->addr = addr;
    }

    void AddMenuItem(const MenuItem &Item){
        menu.push_back(Item);
    }
    vector<MenuItem>& GetItems(){
        return menu;
    }
};

int Restaurant::NextRestrauntId = 0 ;

#endif //RESTAURANT_H