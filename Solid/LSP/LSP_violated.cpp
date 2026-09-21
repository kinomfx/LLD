#include<iostream>
#include<vector>
using namespace std ; 

class Account{
    public:
    virtual void deposite(double amount) = 0 ; 
    virtual void withdraw(double amount) = 0 ;
};

class SavingAccount : public Account {
    private : 
    double balance; 
    public : 
    SavingAccount(){
        balance = 0 ; 
    }
    void deposite(double amount){
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


class CurrentAccount : public Account {
    private : 
    double balance ; 
    public : 
    CurrentAccount(){
        balance = 0 ; 
    }
    void deposite(double amount){
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

class FixedAccount : public Account {
    private : 
    double balance; 
    public :    
    FixedAccount(){
        balance = 0; 
    }
    void deposite(double amount){
        balance+=amount ; 
        cout<<"The new Balance for Fixed Account is :"<<balance<<endl;
    }
    void withdraw(double amount){
        throw logic_error("Withdrawl cant be done using Fixed Deposite Account");
    }
};

class Client{
    private: 
    vector<Account*> accounts ; 
    public : 
    Client(vector<Account*> accounts){
        this->accounts = accounts ; 
    }
    void processTransactions(){
        for(Account* account : accounts){
            account->deposite(1000);
            try{
                account->withdraw(500);
            }
            catch(const logic_error& e ){
                cout<<"Exception : "<<e.what()<<endl;
            }
        }
    }
};

int main(){
    vector<Account*> accounts ; 
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccount());

    Client* client = new Client(accounts);
    client->processTransactions();
    return 0 ; 
}