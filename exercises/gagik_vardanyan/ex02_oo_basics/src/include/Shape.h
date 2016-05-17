/**
* A handle class for shape objects
*/

#ifndef CLASS_SHAPE
#define CLASS_SHAPE
#include <stdexcept>
#include "ShapeBase.h"

class Shape {

private:
    ShapeBase * shapebase; /**< pointer to the ShapeBase object*/

public:
    ///default constructor
    Shape() : shapebase(0) {}

    ///copy constructor
    /// @param s object of the same type
    Shape(const Shape& s) : shapebase(0)
    {
        if(s.shapebase) shapebase = s.shapebase->clone();
    }

    ///constructor from ShapeBase pointer
    /// @param sh pointer to ShapeBase object
    Shape(ShapeBase * sh) { if(sh) shapebase = sh;}

    ///destructor
    ~Shape() {delete shapebase;}

    ///assignment operator
    /// @param s shape object
    /// @return shape object
    Shape& operator=(const Shape& s)
    {
        if(&s != this)
        {
            delete shapebase;
            if(s.shapebase)
                shapebase = s.shapebase->clone();
            else shapebase = 0;
        }
        return *this;
    }

    ///getter of the type of the shape
    /// @return type of the shape
    std::string GetType() const {return shapebase->GetType();}

    ///getter for the number of sides
    /// @return number of sides of the shape
    double GetNSides() const {return shapebase->GetNSides();}

    ///computes the area
    /// @return area of the shape
    double ComputeArea() const {
        if(shapebase) return shapebase->ComputeArea();
        else throw std::runtime_error("Shape is not valid!");
    }

    ///computes the perimeter
    /// @return perimeter of the shape
    double ComputePerimeter() const {
        if(shapebase) return shapebase->ComputePerimeter();
        else throw std::runtime_error("Shape is not valid!");
    }

    ///static binary predicate for area comparison
    /// @param sh1 shape object
    /// @param sh2 shape object
    /// @return True if the sh1 has larger area, False otherwise
    static bool CompareArea(const Shape& sh1, const Shape& sh2) {
        return sh1.ComputeArea() > sh2.ComputeArea();
    }

    ///static binary predicate for perimeter comparison
    /// @param sh1 shape object
    /// @param sh2 shape object
    /// @return True if the sh1 has larger perimeter, False otherwise
    static bool ComparePerimeter(const Shape& sh1, const Shape& sh2) {
        return sh1.ComputePerimeter() > sh2.ComputePerimeter();
    }
};

#endif
