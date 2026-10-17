#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include<vector>
#include<string>
#include "Cart.h"
using namespace std ; 
class User{
    
    int id ; 
    string name; 
    Cart* cart ; 
    string addr ; 
public : 
    User(int id ,const string& name , const string& addr ){
        this->id = id ; 
        this->name = name ; 
        this->cart = new Cart() ;
        this->addr = addr ; 
    }
    ~User(){
        delete cart ;
    }
    //getters and setters 
    string GetName(){
        return this->name ; 
    }
    void SetName(const string& name ){
        this->name = name ; 
    }
    Cart* GetCart(){
        return this->cart;
    }
    string GetLoc(){
        return this->addr;
    }
    string SetAddr(const string& addr){
        return this->addr = addr ; 
    }
};


#endif