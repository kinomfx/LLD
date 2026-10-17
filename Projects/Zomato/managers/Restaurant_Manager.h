#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include<iostream>
#include"../models/Restaurant.h"
#include<vector>
#include<string>
#include<mutex>
#include<algorithm>
using namespace std ; 
// singelton class 
class RestaurantManager{
    static RestaurantManager* instance ;
    static mutex m ;  
    vector<Restaurant*> restaurants ; 
    RestaurantManager(){
        //private constructor 
    }
    public : 
    static RestaurantManager* getInstance(){
        if(instance == nullptr){
            m.lock();
            if(instance == nullptr ){
                instance = new RestaurantManager();
            }
            m.unlock();
        }
        return instance ; 
    }

    void addRestaurant(Restaurant* res){
        restaurants.push_back(res);
    }
    vector<Restaurant*> SearchByLOC(const string& addr){
        string normalizedAddr = addr;
        transform(normalizedAddr.begin() , normalizedAddr.end() , normalizedAddr.begin() , ::tolower);
        vector<Restaurant*> results ; 
        for(Restaurant* restaurant : restaurants){
            string addr2 = restaurant->getLoc();
            transform(addr2.begin() , addr2.end() , addr2.begin() , ::tolower);
            if(normalizedAddr == addr2){
                results.push_back(restaurant);
            }
        }
        return results;
    }
};

RestaurantManager* RestaurantManager:: instance = nullptr ; 
mutex RestaurantManager::m ;
#endif