#ifndef CLASS_TRIANGLE
#define CLASS_TRIANGLE
#include <math.h>
#include "ShapeBase.h"

class Triangle: public ShapeBase {
private:
    double height;
    double base;
protected:
    Triangle* clone() const {return new Triangle(*this);}
public:
    Triangle(){type = "Triangle"; nSides = 3; height= 0; base = 0;}
    Triangle(double h, double b) {type = "Triangle"; nSides = 3; height = h; base = b;}
    double ComputeArea() const {return height*base/2.;}
    double ComputePerimeter() const {return base+2*sqrt(height*height + base*base/4.);}
};

#endif
