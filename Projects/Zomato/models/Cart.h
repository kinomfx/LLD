#ifndef CART_H
#define CART_H

#include<iostream>
#include<string>
#include<vector>
#include "Restaurant.h"
#include "MenuItem.h"
class Cart{
    Restaurant* r ; 
    vector<MenuItem*> items ; 
    public : 
    double GetTotal(){
        double sum = 0 ; 
        for(MenuItem* item : items){
            sum+=item->GetPrice();
        }
        return sum;
    }
    void AddToCart(MenuItem* item){
        if(!r){
            cerr<<"Cart : Set a Restaurant "<<endl;
            return ; 
        }
        items.push_back(item);
    }
    Cart(){
        r = nullptr;
    }
    void clear(){
        items = {};
    }
    bool isEmpty(){
        return(!r || items.size() == 0);
    }
    void SetRestaurant(Restaurant* r){
        this->r = r ; 
    }

    Restaurant* GetRestaurant(){
        return this->r ; 
    }
    const vector<MenuItem*> GetItems(){
        return this->items;
    }
};
#endif