/**
* New type: shape (circle, ..) with functionality defined in class shapeorter
*/
#include <math.h>    //pow, M_PI
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for_each
//#include <memory>  //smart pointers

// abstract base class as interface
class Shape {// abstract class
public:
    Shape(){}
    virtual std::string Type() const =0;
    virtual int Sides () const =0;
    virtual double Perimeter () const =0;
    virtual double Area () const =0;
    virtual ~Shape(){}
};

// type definitions

typedef std::vector<Shape*> collection; // std::unique_ptr
typedef std::vector<Shape*>::size_type ShapeIterator;

// compare functions, const required
bool CompareStrings (const std::string &s1, const std::string &s2){
    return s1.compare(s2);
}

bool CompareSides (const int &s1, const int &s2){
    return s1==s2;
}

// it is crucial to use const (for not changing Shapes content)
bool CompareArea (const Shape *s1, const Shape *s2){
    return s1->Area()>s2->Area();
}

bool ComparePerimeter (const Shape *s1, const Shape *s2){
    return s1->Perimeter()>s2->Perimeter();
}

// class definitions

class Rectangle: public Shape{
    double side1;
    double side2;
public:
    Rectangle(double x, double y) : side1(x), side2(y) {} // constructor
    Rectangle(double z) : side1(z), side2(z) {} // square
    double getSide1() {return side1;}
    double getSide2() {return side2;}
    std::string Type() const {return "Rectangle";}
    int Sides() const {return 4;}
    double Perimeter() const {return (2*(side1+side2));}
    double Area() const {return (side1*side2);}
};

class Circle: public Shape{
    double radius;
public:
    explicit Circle(double r) : radius(r) {} // constructor, default constructor disabled
    double getRadius() {return radius;}
    std::string Type() const {return "Circle";}
    int Sides() const {return -1;} // infinity
    double Perimeter() const {return(2*M_PI*radius);}
    double Area() const {return (M_PI*pow(radius,2));}
};

class Triangle: public Shape{
    double height;
    double base;
public:
    Triangle(double h, double b) : height(h), base(b) {}
    double getHeight () {return height;}
    double getBase () {return base;}
    std::string Type() const {return "Triangle";}
    int Sides() const {return 3;}
    double Perimeter() const {return(base+2*sqrt(pow(height,2.0)+pow(base,2.0)/4));}
    double Area() const {return (height*base/2);}
};

class ShapeSorter{
public:
    void Type(collection &OutputShape,std::string SelectType);
    void Sides(collection &OutputShape,int SelectNumberOfSides);
    void AreaDescending(collection &OutputShape);
    void PerimeterDescending(collection &OutputShape);
};

// functions

void out(std::string Type, double val) {
    std::cout << Type << "\t" << val << std::endl;
}

void out(std::string Type, double val1, double val2) {
    std::cout << Type << "\t" << val1 << "\t" << val2 << std::endl;
}

void out(std::string Type, std::string val) {
    std::cout << Type << "\t" << val << std::endl;
}

// member functions

void ShapeSorter::Type(collection &OutputShape, std::string SelectType){
    ShapeIterator i = 0;
    try{
        while (i!=OutputShape.size()){
            if (CompareStrings(SelectType,OutputShape[i]->Type())){
                OutputShape.erase(OutputShape.begin()+i);
                --i;//do not update iterator position in vector
            }
            ++i;
        }
    }
    catch (std::exception const& ex) {//catch standard exception
        std::cout << "Exception: " << ex.what() <<std::endl;
    }
}

void ShapeSorter::Sides(collection &OutputShape, int NumberOfSides){
    ShapeIterator i = 0;
    try{
        while (i!=OutputShape.size()){
            if (!CompareSides(NumberOfSides,OutputShape[i]->Sides())){
                OutputShape.erase(OutputShape.begin()+i);
                --i;//do not update iterator position in vector
            }
            ++i;
        }
    }
    catch (std::exception const& ex) {//catch standard exception
        std::cout << "Exception: " << ex.what() <<std::endl;
    }
}

void ShapeSorter::AreaDescending(collection &Shapes){
    sort(Shapes.begin(),Shapes.end(),CompareArea);
}

void ShapeSorter::PerimeterDescending(collection &Shapes){
    sort(Shapes.begin(),Shapes.end(),ComparePerimeter);
}

// template function in order to delete classes
template <typename T>
void DeleteShape(T* const ptr){delete ptr;}

int main(int argc, char** argv){
    try{

        collection cShape; // input shapes

        cShape.push_back(new Rectangle(4.5,2.0));// std::make_unique
        cShape.push_back(new Rectangle(1.5,2.0));
        cShape.push_back(new Circle(3.0));
        cShape.push_back(new Rectangle(4.0));
        cShape.push_back(new Triangle(2.0,2.0));

        collection sShape(cShape); // Shape's copy constructor
        collection tShape(cShape); // Shape's copy constructor

        ShapeSorter cSorter;

        std::cout << "All shapes, perimeter descending " << std::endl;
        cSorter.PerimeterDescending(cShape);
        for(ShapeIterator i = 0; i!=cShape.size(); ++i){
            out(cShape[i]->Type(),cShape[i]->Perimeter());
        }
        std::cout << "\n" << std::endl;

        std::cout << "All shapes, area descending " << std::endl;
        cSorter.AreaDescending(cShape);
        for(ShapeIterator i = 0; i!=cShape.size(); ++i){
            out(cShape[i]->Type(),cShape[i]->Area());
        }
        std::cout << "\n" << std::endl;

        std::cout << "All rectangles (side1, side2)" << std::endl;
        cSorter.Type(sShape,"Rectangle");
        for(ShapeIterator i = 0; i!=sShape.size(); ++i){
            Rectangle * rect = dynamic_cast<Rectangle*>(sShape[i]);
            if(rect!=NULL)
                out(sShape[i]->Type(),rect->getSide1(),rect->getSide2());
        }
        std::cout << "\n" << std::endl;

        std::cout << "All shapes with 4 sides (side1, side2)" << std::endl;
        cSorter.Sides(tShape,4);
        for(ShapeIterator i = 0; i!=tShape.size(); ++i){
            Rectangle * rect = dynamic_cast<Rectangle*>(sShape[i]);
            if(rect!=NULL)
                out(sShape[i]->Type(),rect->getSide1(),rect->getSide2());
        }
        std::cout << "\n" << std::endl;

        std::for_each(cShape.begin(), cShape.end(), DeleteShape<Shape>); // deletes

    }
    catch (std::exception const& ex) {//catch standard exception
        std::cout << "Exception: " << ex.what() <<std::endl;
        
    }
    return 0;

}
