#include<iostream>
#include<vector>
using namespace std ; 

class Persistence{
    public :
    virtual void save() = 0 ; 
};
class SQLDB : public Persistence {
    public : 
    void save(){
        cout<<"saving to SQL DB ...."<<endl;
    }
};

class MongoDB : public Persistence{
    void save(){
        cout<<"saving to Mongo DB ...."<<endl;
    }
};
class UserService {
public :
    Persistence* p ;
    UserService(Persistence* p ){
        this->p = p ; 
    }
    void Save(){
        p->save();
    }
};

int main(){
    SQLDB* sql = new SQLDB();
    MongoDB* mongo = new MongoDB();
    UserService* service1 = new UserService(sql);
    UserService* service2 = new UserService(mongo);
    service1->Save();
    service2->Save();
}