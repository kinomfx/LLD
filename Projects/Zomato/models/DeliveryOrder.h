#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H
#include<iostream>
#include<string>
#include<vector>
#include "Order.h"
using namespace std ; 

class DeliveryOrder : public Order {
    private : 
        string userAddr ; 
    public : 
        DeliveryOrder(){
            userAddr = "";
        }
        string getType() const override {
            return "Delivery";
        }
        //Getters and Setters
        void SetUserAddr(const string& userAddr){
            this->userAddr = userAddr;
        }
        string GetUserAddr(){
            return this->userAddr;
        }
};

#endif
