#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "../models/Order.h"
#include "../models/MenuItem.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std ; 
class NotificationSystem{
    public : 
    static void notify(Order* order){
        cout<<"Notification NEW : "<<"-------------------"<<"order placed !! "<<endl;
        cout<<"Order ID : "<<order->GetOrderId()<<endl;
        cout<<"Customer : "<<order->GetUser()->GetName()<<endl;
        cout<<"Restaurant : "<<order->GetRestaurant()->GetName()<<endl;
        cout<<"Items Ordered : \n";
        vector<MenuItem*> items  = order->GetItems();
        cout<<"Total : "<<order->GetTotal()<<endl;
        cout<<"Scheduled for : "<<order->GetScheduled()<<endl;;
        cout<<"Payment Done !! \n";
        cout<<"--------------------------"<<endl;
    }
};
#endif