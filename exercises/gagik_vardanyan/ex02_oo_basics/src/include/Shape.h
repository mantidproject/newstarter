/**
* A handle class for shape objects
*/

#ifndef CLASS_SHAPE
#define CLASS_SHAPE
#include "ShapeBase.h"

class Shape {
public:
    ///default constructor
    Shape() : cp(0) {}

    ///copy constructor
    /// @param s object of the same type
    Shape(const Shape& s) : cp(0) {if(s.cp) cp = s.cp->clone();}

    ///constructor from ShapeBase pointer
    /// @param sh pointer to ShapeBase object
    Shape(ShapeBase * sh) { if(sh) cp = sh;}

    ///destructor
    ~Shape() {delete cp;}

    ///assignment operator
    /// @param s shape object
    /// @return shape object
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

    ///getter of the type of the shape
    /// @return type of the shape
    std::string GetType() const {return cp->GetType();}

    ///getter for the number of sides
    /// @return number of sides of the shape
    double GetNSides() const {return cp->GetNSides();}

    ///computes the area
    /// @return area of the shape
    double ComputeArea() const {
        if(cp) return cp->ComputeArea();
        else return 0;
    }

    ///computes the perimeter
    /// @return perimeter of the shape
    double ComputePerimeter() const {
        if(cp) return cp->ComputePerimeter();
        else return 0;
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

private:
    ShapeBase * cp; /**< pointer to the ShapeBase object*/
};

#endif
