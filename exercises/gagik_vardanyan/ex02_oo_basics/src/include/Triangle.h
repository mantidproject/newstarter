/*!
* A class to define a triangle
*/

#ifndef CLASS_TRIANGLE
#define CLASS_TRIANGLE
#include <cmath>
#include "ShapeBase.h"

class Triangle: public ShapeBase {
private:
    double height; /**< height of the triangle*/
    double base; /**< base of the triangle*/

protected:
    ///clone function
    /// @return new triangle object
    Triangle* clone() const {return new Triangle(*this);}

public:
    ///default constructor
    Triangle()
    {
        type = "Triangle";
        nSides = 3;
        height= 0;
        base = 0;
    }

    ///constructor from height and base
    /// @param h height of the triangle
    /// @param b base of the triangle
    Triangle(double h, double b)
    {
        type = "Triangle";
        nSides = 3;
        height = h;
        base = b;
    }

    ///computes the area
    /// @return the area
    double ComputeArea() const {return height*base/2.;}

    ///computes the perimeter
    /// @return the perimeter
    double ComputePerimeter() const {return base+2*sqrt(height*height + base*base/4.);}
};

#endif
