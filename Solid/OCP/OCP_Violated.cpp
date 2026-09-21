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

class StoreToDB{
    public : 
    ShoppingCart* s ; 
    StoreToDB(ShoppingCart* s){
        this->s  = s ; 
    }
    void saveToSQL(){
        cout<<"SAVING TO SQL ....."<<endl;
    }
    void saveToMongo(){
        cout<<"SAVING TO MONGO ......"<<endl;
    }
    void saveToFile(){
        cout<<"SAVING TO FILE ....."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->add(new Product("Laptop" , 1500));
    cart->add(new Product("PS5" , 40000));
    GetInvoice* invoice = new GetInvoice(cart);
    invoice->PrintInvoice();
    StoreToDB* DB = new StoreToDB(cart);
    DB->saveToSQL();
    DB->saveToFile();
    DB->saveToMongo();

}