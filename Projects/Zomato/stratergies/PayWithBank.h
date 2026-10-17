#ifndef PAY_WITH_BANK_H
#define PAY_WITH_BANK_H
#include<iostream>
#include "PaymentStratergy.h"
using namespace std ; 
class PayWithBank : public PaymentStratergy{
    void pay(double amount) override{
        cout<<"Payed :"<<amount<<" Via NetBanking"<<endl;
    }
};

#endif