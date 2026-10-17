#ifndef ZOMATO_H
#define ZOMATO_H
#include<iostream>
#include<vector>
#include<string>
#include "models/Cart.h"
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/MenuItem.h"
#include "managers/Restaurant_Manager.h"
#include "stratergies/PaymentStratergy.h"
#include "stratergies/PayWithBank.h"
#include "stratergies/PayWithUPI.h"
#include "factories/OrderFactory.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/Notification.h"
class Zomato{
    public : 
        Zomato(){
            InitializeRestaurants();
        }
        void InitializeRestaurants(){
            Restaurant* r1 = new Restaurant("Bikaner" , "Delhi");
            r1->AddMenuItem(MenuItem("P1" , "chole bhature" , 150.0));
            r1->AddMenuItem(MenuItem("P2" , "samosa" , 15.0));

            Restaurant* r2 = new Restaurant("haldiram" , "Kolkata");
            r2->AddMenuItem(MenuItem("P1" , "Raj Kachori" , 120.0));
            r2->AddMenuItem(MenuItem("P2" , "Pav Bhaji" , 105.0));
            r2->AddMenuItem(MenuItem("P3" , "dhokla" , 150.0));
            

            Restaurant* r3 = new Restaurant("Momos wali aunty" , "Bengaluru");
            r3->AddMenuItem(MenuItem("P1" , "paneer momos" , 100.0));
            r3->AddMenuItem(MenuItem("P2" , "kurkure momos" , 150.0));
            

            RestaurantManager* res_manager = RestaurantManager::getInstance();
            res_manager->addRestaurant(r1);
            res_manager->addRestaurant(r2);
            res_manager->addRestaurant(r3);

        }

        vector<Restaurant*> GetRestaurant(string& loc){
            return RestaurantManager::getInstance()->SearchByLOC(loc);
        }

        void SelectRestaurant(User* user , Restaurant* res){
            Cart* cart = user->GetCart();
            cart->SetRestaurant(res);
        }
        void addToCart(User* user , string& itemCode){
            Restaurant* res = user->GetCart()->GetRestaurant();
            if(!res){
                cout<<"Please select a restaurant first"<<endl;
                return ; 
            }
            for(auto& item : res->GetItems()){
                if(item.GetCode() == itemCode){
                    user->GetCart()->AddToCart(&item);
                    break;
                }
            }
        }
        Order* checkout(User* user , string orderType , PaymentStratergy* p , OrderFactory* fac){
            if(user->GetCart()->isEmpty()){
                return nullptr;
            }
            Cart* cart = user->GetCart();
            Restaurant* ordered_res = cart->GetRestaurant();
            vector<MenuItem*> items = cart->GetItems();
            Order* order = fac->CreateOrder(user , cart , ordered_res , items , p , orderType);
            return order;
        }
        Order* checkoutnow(User* user , string orderType , PaymentStratergy* p){
            return checkout(user , orderType , p , new NowOrderFactory());
        }
        Order* checkoutScheduled(User* user , string orderType , PaymentStratergy* p , string scheduledTime ){
            return checkout(user , orderType , p , new ScheduledOrderFactory(scheduledTime));
        }
        void payForOrder(User* user , Order* order){
            bool isPaymentSuccessful = order->ProcessPayment(order->GetTotal());
            if(isPaymentSuccessful){
                user->GetCart()->clear();
                NotificationSystem* Notification = new NotificationSystem();
                Notification->notify(order);
            }
        }

};

#endif