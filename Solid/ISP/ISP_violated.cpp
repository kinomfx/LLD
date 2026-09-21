#include<iostream>
#include<vector>
using namespace std ; 

class Shape{
    private : 
    double side ; 
    public : 
    virtual double area() = 0 ; 
    virtual double volume() = 0 ; 

};

class Square : public Shape {
    private : 
    double side ;
    public : 
    Square(double s ) {
        side = s; 
    }
    double area(){
        return side*side; 
    }
    double volume(){
        throw logic_error("Volume cant be formed with 2D shapes HAHAHAH BOZO ....");
    }
};

class Rectangle : public Shape {
    private : 
    double length , width  ;   
    public :  
    Rectangle(double length , double width ){
        this->length = length;
        this->width = width;
    }
    double area(){
        return length*width; 
    }
    double volume(){
        throw logic_error("Volume cant be formed with 2D shapes HAHAHAH BOZO ....");
    }

};

class Cube : public Shape{
    double side ; 
    public : 
    Cube(double s  ) {
        this->side = s ; 
    }
    double area(){
        return 6*side*side;
    }
    double volume(){
        return side*side*side;
    }
};
int main(){
    Shape* square = new Square(6);
    Shape* rectangle = new Rectangle(6 , 6);
    Shape* cube = new Cube(6);

    cout<<"Square Area : "<<square->area()<<endl;
    try{
        cout<<"Square Vol : "<<square->volume()<<endl;
    }catch(logic_error& e){
        cout<<e.what()<<endl;
    }

    cout<<"Rectangle Area : "<<rectangle->area()<<endl;
    try
    {
        cout<<"Rectangle Vol : "<<rectangle->volume()<<endl;
    }catch(logic_error& e){
        cout<<e.what()<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    cout<<"Cube Area : "<<cube->area()<<endl;
    cout<<"Cube Vol : "<<cube->volume()<<endl;
}