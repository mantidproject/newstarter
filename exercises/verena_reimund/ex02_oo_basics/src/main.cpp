/**
* New type: shape (circle, ..) with functionality defined in class shapeorter
*/
#include <math.h>    //pow, M_PI
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for_each
//#include <memory>  //smart pointers

// abstract base class
class shape{
public:
    shape(){}
    virtual std::string type() const =0;
    virtual int number_of_sides() const =0;
    virtual double perimeter () const =0;
    virtual double area () const =0;
    virtual ~shape(){}
};

// type definitions

typedef std::vector<shape*> collection; // std::unique_ptr
typedef std::vector<shape*>::size_type its;

// compare functions, const required
bool compare_strings (const std::string &s1, const std::string &s2){
    return s1.compare(s2)==0;
}

bool compare_volume (const shape *s1, const shape *s2){
    return s1->area()>s2->area();
}

bool compare_perimeter (const shape *s1, const shape *s2){
    return s1->perimeter()>s2->perimeter();
}

bool compare_sides (const int &s1, const int &s2){
    return s1==s2;
}

// class definitions

class rectangle: public shape{
    double side1;
    double side2;
public:
    rectangle(double x, double y) : side1(x), side2(y) {} // constructor
    rectangle(double z) : side1(z), side2(z) {} // constructor number_of_sides
    std::string type() const {return "Rectangle";}
    int number_of_sides() const {return 4;}
    double perimeter() const {return (2*(side1+side2));}
    double area() const {return (side1*side2);}
};

class circle: public shape{
    double radius;
public:
    explicit circle(double r) : radius(r) {} // constructor, default constructor disabled
    std::string type() const {return "Circle";}
    int number_of_sides() const {return -1;} // infinity, not an unsigned int
    double perimeter() const {return(2*M_PI*radius);}
    double area() const {return (M_PI*pow(radius,2));}
};

class triangle: public shape{
    double height;
    double base;
public:
    triangle(double h, double b) : height(h), base(b) {}
    std::string type() const {return "Triangle";}
    int number_of_sides() const {return 3;}
    double perimeter() const {return(base+2*sqrt(pow(height,2.0)+pow(base,2.0)/4));}
    double area() const {return (height*base/2);}
};

class shapesorter{
    collection shape;
public:
    explicit shapesorter(collection s) : shape(s) {}
    void type(std::string select_type);
    void sides(int select_number_of_sides);
    void volume_dec();
    void perimeter_dec();
};

// member functions

void out(std::string type, double val) {
    std::cout << type << "\t" << val << std::endl;
}

void out(std::string type, double val1, double val2) {
    std::cout << type << "\t" << val1 << "\t" << val2 << std::endl;
}


// would like to print values of derived class members like side1, side2, .. using dynamic_cast

void shapesorter::type(std::string select_type){
    std::cout << "shape of type : " << select_type << std::endl;
    for(its i = 0; i!=shape.size(); ++i){
        if (compare_strings(select_type,shape[i]->type())){
            out(shape[i]->type(),shape[i]->area());
        }
    }
    std::cout << '\n' << std::endl;
}

void shapesorter::sides(int number_of_sides){
    std::cout << "shape with number of sides : " << number_of_sides << std::endl;
    for(its i = 0; i!=shape.size(); ++i){
        if (compare_sides(number_of_sides,shape[i]->number_of_sides())){
            out(shape[i]->type(),shape[i]->number_of_sides());
        }
    }
}

void shapesorter::volume_dec(){
    sort(shape.begin(),shape.end(),compare_volume);
}

void shapesorter::perimeter_dec(){
    sort(shape.begin(),shape.end(),compare_perimeter);
}

// template function in order to delete classes
template <typename T>
void delete_shape(T* const ptr){delete ptr;}

int main(int argc, char** argv){
    try{

        collection cshape;

        cshape.push_back(new rectangle(4.5,2.0));// std::make_unique
        cshape.push_back(new rectangle(1.5,2.0));
        cshape.push_back(new circle(3.0));
        cshape.push_back(new rectangle(4.0));
        cshape.push_back(new triangle(2.0,2.0));

        shapesorter csorter(cshape);
        csorter.type("Rectangle");
        csorter.sides(4);
        csorter.volume_dec();
        csorter.perimeter_dec();

        std::for_each(cshape.begin(), cshape.end(), delete_shape<shape>); // deletes
        return 0;

    }
    catch (std::exception const& ex) {//catch standard exception
        std::cout << "Exception: " << ex.what() <<std::endl;
        return -1;
    }

}
