#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include<iostream>
#include<vector>
#include<string>
#include "../models/Order.h"
using namespace std ; 

class OrderFactory{
    public : 
    virtual Order* CreateOrder(User* user , Cart* cart  , Restaurant* restaurant , const vector<MenuItem*> items , PaymentStratergy* paymentstratergy , const string OrderType) = 0 ; 
};

#endif