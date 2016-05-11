#ifndef CLASS_CIRCLE
#define CLASS_CIRCLE
#define _USE_MATH_DEFINES
const double PI = 3.14; //Windows builds don't recognise M_PI
#include <cmath>
#include "ShapeBase.h"


class Circle: public ShapeBase {
private:
    double radius;
protected:
    Circle* clone() const {return new Circle(*this);}
public:
    Circle()
    {
        type = "Circle";
        nSides = 0;
        radius = 0;
    }
    Circle(double s)
    {
        type = "Circle";
        nSides = 0;
        radius = s;
    }
    double ComputeArea() const {return PI*radius*radius;}
    double ComputePerimeter() const {return 2*PI*radius;}
};

#endif
