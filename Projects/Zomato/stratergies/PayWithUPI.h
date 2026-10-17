#ifndef PAY_WITH_UPI_H
#define PAY_WITH_UPI_H
#include "PaymentStratergy.h"
#include<iostream>
using namespace std ; 
class PayWithUPI : public PaymentStratergy {
    void pay(double amount ) override {
        cout<<"Paying via UPI ..... TENG TEDENG KHAATE ME "<<amount<<" prapt hue "<<endl;
    }
};

#endif 