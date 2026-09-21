#include<iostream>
#include<vector>
using namespace std ; 

class DepositeOnlyAccount{
    public : 
    virtual void deposit(double amount) = 0 ; 
};

class WithdrawOnlyAccount : public DepositeOnlyAccount{
    public : 
    virtual void withdraw(double amount) = 0 ; 
};

class SavingAccount :  public WithdrawOnlyAccount {
    private : 
    double balance; 
    public : 
    SavingAccount(){
        balance = 0 ; 
    }
    void deposit(double amount){
        balance+=amount ; 
        cout<<"The new Balance for Saving Account is :"<<balance<<endl;
    }
    void withdraw(double amount){
        if(balance < amount ){
            cout<<"You dont have enough balance HAHAHHAHA ... "<<endl;
            return ; 
        }
        balance-=amount; 
        cout<<"The new Balance for Saving Account is :"<<balance<<endl;   
    }
};


class CurrentAccount : public WithdrawOnlyAccount {
    private : 
    double balance ; 
    public : 
    CurrentAccount(){
        balance = 0 ; 
    }
    void deposit(double amount){
        balance+=amount ; 
        cout<<"The new Balance for Current Account is :"<<balance<<endl;
    }
    void withdraw(double amount){
        if(balance < amount ){
            cout<<"You dont have enough balance HAHAHHAHA ... "<<endl;
            return ; 
        }
        balance-=amount; 
        cout<<"The new Balance for Current Account is :"<<balance<<endl;   
    }
};

class FixedAccount : public DepositeOnlyAccount {
    private : 
    double balance; 
    public :    
    FixedAccount(){
        balance = 0; 
    }
    void deposit(double amount){
        balance+=amount ; 
        cout<<"The new Balance for Fixed Account is :"<<balance<<endl;
    }
};

class Client{
    private: 
    vector<DepositeOnlyAccount*> DepositeOnlyaccounts ; 
    vector<WithdrawOnlyAccount*> WithdrawOnlyaccounts ; 
    public : 
    Client(vector<DepositeOnlyAccount*> DepositeOnlyaccounts , vector<WithdrawOnlyAccount*> WithdrawOnlyaccounts){
        this->DepositeOnlyaccounts = DepositeOnlyaccounts ; 
        this->WithdrawOnlyaccounts = WithdrawOnlyaccounts ; 
    }
    void processTransactions(){
        for(DepositeOnlyAccount* account : DepositeOnlyaccounts){
            account->deposit(1000);
        }
        for(WithdrawOnlyAccount* account : WithdrawOnlyaccounts){
            account->deposit(1000);
            account->withdraw(500);
        }
    }
};

int main(){
    vector<DepositeOnlyAccount*> DepositeOnlyaccounts ; 
    vector<WithdrawOnlyAccount*> WithdrawOnlyaccounts ;
    
    DepositeOnlyaccounts.push_back(new FixedAccount());
    WithdrawOnlyaccounts.push_back(new SavingAccount());
    WithdrawOnlyaccounts.push_back(new CurrentAccount());
    Client* client = new Client(DepositeOnlyaccounts , WithdrawOnlyaccounts);
    client->processTransactions();
    return 0 ; 
}