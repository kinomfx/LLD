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

//violating SRP : Shopping cart has too many responsibilities 
class ShoppingCart{
    private : 
        vector<Product*> products ; 
    public : 
        void add(Product* p){
            products.push_back(p);
        }
        const vector<Product*>& getProducts(){
            return products; 
        }
        double CalcTotalPrice(){
            double total = 0 ; 
            for(auto x : products){
                total+=x->price;
            }
            return total ; 
        }
        // Violating SRP here as it should be a SINGLE RESPONSIBILITY 
        void PrintInvoice(){
            cout<<"Shopping Cart Invoice :"<<endl;
            for(auto p : products){
                cout<<p->name<<" - $"<<p->price<<endl;
            }
            cout<<"Total : "<<CalcTotalPrice()<<endl;
        }

        // Violating SRP here as it should be a SINGLE RESPONSIBILITY 
        void saveToDB(){
            cout<<"SAVING TO DB ....."<<endl;
        }
};


int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->add(new Product("Laptop" , 1500));
    cart->add(new Product("PS5" , 40000));
    cart->PrintInvoice();
    cart->saveToDB();

}