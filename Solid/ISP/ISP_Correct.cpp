#include<iostream>
#include<vector>
using namespace std ; 

class TwoDimensionShape{
    private : 
    double side ; 
    public : 
    virtual double area() = 0 ; 

};

class ThreeDimensionShape{
    private : 
    double side ; 
    public : 
    virtual double area() = 0  ; 
    virtual double volume() = 0 ; 

};

class Square : public TwoDimensionShape {
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

class Rectangle : public TwoDimensionShape {
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

class Cube : public ThreeDimensionShape{
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
    TwoDimensionShape* square = new Square(6);
    TwoDimensionShape* rectangle = new Rectangle(6 , 6);
    ThreeDimensionShape* cube = new Cube(6);

    cout<<"Square Area : "<<square->area()<<endl;

    cout<<"Rectangle Area : "<<rectangle->area()<<endl;
    

    cout<<"Cube Area : "<<cube->area()<<endl;
    cout<<"Cube Vol : "<<cube->volume()<<endl;
}