#include<iostream>
#include<string>
#include<vector>
using namespace std ; 
class Product{
    public : 
    string name ; 
    double price ; 
    Product(string name , double price){
        this->name = name ; 
        this->price = price ; 
    }
};


class ShoppingCart{
    private : 
    vector<Product*> products ; 
    public : 
    void add(Product* p){
        products.push_back(p);
    }
    double CalcTotalPrice(){
        double total = 0 ; 
        for(auto x : products){
            total+=x->price;
        }
        return total ; 
    }
    const vector<Product*>& getProducts(){
        return products; 
    }
};

class GetInvoice{
    public : 
    ShoppingCart* s ; 
    
        GetInvoice(ShoppingCart* s ){
            this->s = s ; 
        }
        void PrintInvoice(){
            cout<<"Shopping Cart Invoice :"<<endl;
            for(auto p : s->getProducts()){
                cout<<p->name<<" - $"<<p->price<<endl;
            }
            cout<<"Total : "<<s->CalcTotalPrice()<<endl;
        }
};

class DBPersistance{
    public : 
    ShoppingCart* cart ; 
    DBPersistance(ShoppingCart* cart){
        this->cart = cart;
    }
    virtual void save() = 0;
};

class SaveToSQL : public DBPersistance {
    public : 
    ShoppingCart* cart ; 
    SaveToSQL(ShoppingCart* cart) : DBPersistance(cart){
        this->cart = cart ; 
    }
    void save() override{
        cout<<"SAVE TO SQL ....."<<endl;
    }
};

class SaveToMongo :public  DBPersistance {
    public : 
    ShoppingCart* cart ; 
    SaveToMongo(ShoppingCart* cart ): DBPersistance(cart){
        this->cart = cart ; 
    }
    void save()override{
        cout<<"SAVE TO MONGO ....."<<endl;
    }
};

class SaveToFile :public  DBPersistance{
    public : 
    ShoppingCart* cart ; 
    SaveToFile(ShoppingCart* cart ): DBPersistance(cart){
        this->cart = cart ; 
    }
    void save()override{
        cout<<"SAVE TO FILE ....."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->add(new Product("Laptop" , 1500));
    cart->add(new Product("PS5" , 40000));
    GetInvoice* invoice = new GetInvoice(cart);
    invoice->PrintInvoice();
    DBPersistance* DB_SQL = new SaveToSQL(cart);
    DBPersistance* DB_Mongo = new SaveToMongo(cart);
    DBPersistance* DB_File = new SaveToFile(cart);
    DB_SQL->save();
    DB_Mongo->save();
    DB_File->save();

}