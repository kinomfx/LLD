#ifndef ORDER_H
#define ORDER_H
#include<iostream>
#include<string>
#include<vector>
#include "Restaurant.h"
#include "User.h"
#include "MenuItem.h"
#include "../stratergies/PaymentStratergy.h"
using namespace std ; 
class Order{
    static int NextOrderId ; 
    int id ; 
    User* user ; 
    Restaurant* restraurant;
    vector<MenuItem*> items ;
    PaymentStratergy* paymentstratergy;
    double total ; 
    string scheduled ; 
public : 
    Order(){
        user = nullptr ; 
        restraurant = nullptr;
        paymentstratergy = nullptr;
        total = 0.0;
        scheduled = "";
        id = ++NextOrderId;
    }
    ~Order(){
        
    }

    bool ProcessPayment(double amount){
        if(paymentstratergy){
            paymentstratergy->pay(amount);
            return true ; 
        }
        else{
            cerr<<"Please choose a payment stratergy"<<endl;
            return false;
        }
    }

    virtual string getType() const = 0 ; 

    //Getters and Setters 
    int GetOrderId(){
        return this->id ; 
    }
    void SetUser(User* user){
        this->user = user ; 
    }
    User* GetUser(){
        return this->user;
    }
    void SetRestaurant(Restaurant* restaurant){
        this->restraurant = restaurant;
    }
    Restaurant* GetRestaurant(){
        return this->restraurant;
    }
    void SetItems(const vector<MenuItem*> items ){
        this->items = items;
    }
    const vector<MenuItem*> GetItems(){
        return this->items;
    }
    void SetPaymentStratergy(PaymentStratergy* paymentstratergy ){
        this->paymentstratergy = paymentstratergy;
    }
    void SetTotal(double total){
        this->total = total ; 
    }
    double GetTotal(){
        return this->total;
    }
    string GetScheduled(){
        return this->scheduled;
    }
    void SetScheduled(string schedule){
        this->scheduled = schedule;
    }
};

int Order::NextOrderId = 0 ; 


#endif