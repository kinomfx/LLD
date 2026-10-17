#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H
#include "Order.h"
using namespace std ; 
class PickupOrder : public Order{
    private : 
        string restaurantAddr ; 
    public : 
        string getType() const override {
            return "Pickup";
        }
        PickupOrder(){
            restaurantAddr = "";
        }
        string GetRestaurantAddr(){
            return this->restaurantAddr;
        }
        void SetRestaurantAddr(const string& addr){
            restaurantAddr = addr;
        }
};


#endif