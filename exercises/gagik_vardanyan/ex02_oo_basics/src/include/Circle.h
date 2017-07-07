/*!
* A class to define a circle
*/

#ifndef CLASS_CIRCLE
#define CLASS_CIRCLE
#include <cmath>
#include "Shape.h"


class Circle: public Shape {
private:
    double radius; /**< radius of the circle*/

public:
    ///clone function
    /// @return new circle object
    Circle* clone() const {return new Circle(*this);}

    ///default constructor
    Circle()
    {
        type = "Circle";
        nSides = 0;
        radius = 0;
    }

    ///constructor from radius
    /// @param s radius of the circle
    Circle(double s)
    {
        type = "Circle";
        nSides = 0;
        radius = s;
    }

    ///computes the area
    /// @return the area
    double ComputeArea() const {return M_PI*radius*radius;}

    ///computes the perimeter
    /// @return the perimeter
    double ComputePerimeter() const {return 2*M_PI*radius;}
};

#endif
