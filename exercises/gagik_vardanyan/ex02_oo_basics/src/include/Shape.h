#ifndef CLASS_SHAPE
#define CLASS_SHAPE
#include "ShapeBase.h"

class Shape {
public:
    //default constructor
    Shape() : cp(0) {}

    //copy constructor
    Shape(const Shape& s) : cp(0) {if(s.cp) cp = s.cp->clone();}

    //constructor from shapebase pointer
    Shape(ShapeBase * sh) {cp = sh;}

    //destructor
    ~Shape() {delete cp;}

    //assignment operator
    Shape& operator=(const Shape& s)
    {
        if(&s != this)
        {
            delete cp;
            if(s.cp)
                cp = s.cp->clone();
            else cp = 0;
        }
        return *this;
    }

    //returns the type of the shape
    std::string GetType() const {return cp->GetType();}

    //returns the number of sides of the shape
    double GetNSides() const {return cp->GetNSides();}

    //computes the area
    double ComputeArea() const {
        if(cp) return cp->ComputeArea();
        else throw std::runtime_error("Uninitialized Shape");
    }

    //computes the perimeter
    double ComputePerimeter() const {
        if(cp) return cp->ComputePerimeter();
        else throw std::runtime_error("Uninitialized Shape");
    }

    //binary predicate for area comparison
    static bool CompareArea(const Shape& sh1, const Shape& sh2) {
        return sh1.ComputeArea() > sh2.ComputeArea();
    }

    //binary predicate for perimeter comparison
    static bool ComparePerimeter(const Shape& sh1, const Shape& sh2) {
        return sh1.ComputePerimeter() > sh2.ComputePerimeter();
    }

private:
    ShapeBase * cp;
};

#endif
