#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include<iostream>
#include<vector>
#include<string>
#include "../models/Order.h"
#include<mutex>
using namespace std ; 

class OrderManager{
    static OrderManager* instance ; 
    static mutex m ; 
    vector<Order*> orders ; 
    OrderManager(){
        
    }
    public : 
        OrderManager* GetInstance(){
            if(instance == nullptr){
                m.lock();
                if(instance == nullptr){
                    instance = new OrderManager();
                }
                m.unlock();
            }
            return instance ; 
        }
        void AddOrder(Order* o){
            this->orders.push_back(o);
        }
        vector<Order*> GetOrders(){
            return this->orders;
        }
        void ListOrder(){
            cout<<"_______ ALL ORDERS ________"<<endl;
            for(Order* order: orders){
                cout<<"The user's name is :"<<order->GetUser()->GetName()<<endl;
                cout<<"The restaurant's name is :"<<order->GetRestaurant()->GetName()<<endl;
                cout<<"The total bill is : "<<order->GetTotal()<<endl;
                cout<<"It is scheduled at : "<<order->GetScheduled();
            }
        }

};

OrderManager* OrderManager::instance  = nullptr ; 
mutex OrderManager::m; 

#endif