#ifndef CLASS_CIRCLE
#define CLASS_CIRCLE
#include <math.h>
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
    double ComputeArea() const {return M_PI*radius*radius;}
    double ComputePerimeter() const {return 2*M_PI*radius;}
};

#endif
