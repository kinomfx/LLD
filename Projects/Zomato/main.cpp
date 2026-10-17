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
#include "Zomato.h"
using namespace std ; 


int main(){
    Zomato* app = new Zomato();
    User* user = new User(101 , "Monik" , "Delhi");

    string loc = user->GetLoc();
    vector<Restaurant*> restaurant_list = app->GetRestaurant(loc);

    if(restaurant_list.size() == 0){
        cout<<"No restaurant Found"<<endl;
        return 0 ; 
    }
    cout<<"Found Restaurant : "<<endl;
    for(auto res : restaurant_list){
        cout<<res->GetName()<<endl;
    }

    app->SelectRestaurant(user , restaurant_list[0]);
    string P1 = "P1";
    string P2 = "P2";
    app->addToCart(user , P1);
    app->addToCart(user , P2);


    Order* order = app->checkoutnow(user , "Delivery" , new PayWithUPI());
    app->payForOrder(user , order);

    delete app ; 
    delete user ; 
    return 0 ; 

}