#include<iostream>
#include<vector>
using namespace std ; 

class SQLDB{
public : 
    void Save(){
        cout<<"SAVING TO SQL ...."<<endl;
    }  
};

class MongoDB{
public : 
    void Save(){
        cout<<"SAVING TO MONGO...."<<endl;
    }
};



class Application {
    public :
    SQLDB* sql  = new SQLDB();
    MongoDB* mongo = new MongoDB();
    void SaveToSQL(){
        sql->Save();
    }
    void SaveToMongo(){
        mongo->Save();
    }
};


int main(){
    Application* myapp = new Application();
    myapp->SaveToMongo();
    myapp->SaveToSQL();
    return 0 ; 

}