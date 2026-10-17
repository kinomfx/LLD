#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H
#include<iostream>
#include "OrderFactory.h"
#include<vector>
#include<string>
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std ; 

class ScheduledOrderFactory : public OrderFactory{
    string scheduledTime ; 

    public : 
    ScheduledOrderFactory(string scheduledTime){
        this->scheduledTime = scheduledTime;
    }
    Order* CreateOrder(User* user , Cart* cart  , Restaurant* restaurant , const vector<MenuItem*> items , PaymentStratergy* paymentstratergy , const string OrderType) override{
        Order* order = nullptr ; 
        if(OrderType == "Delivery"){
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->SetUserAddr(user->GetLoc());
            order = deliveryOrder ; 
        }
        else{
            auto pickupOrder = new PickupOrder();
            pickupOrder->SetRestaurantAddr(restaurant->getLoc());
            order = pickupOrder;
        }
        order->SetUser(user);
        order->SetPaymentStratergy(paymentstratergy);
        order->SetItems(items);
        order->SetRestaurant(restaurant);
        order->SetTotal(cart->GetTotal());
        order->SetScheduled(scheduledTime);
        return order ; 
    }
};
#endif