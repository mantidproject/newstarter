#ifndef CLASS_RECTANGLE
#define CLASS_RECTANGLE
#include "ShapeBase.h"

class Rectangle: public ShapeBase {
private:
    double side1;
    double side2;
protected:
    Rectangle* clone() const {return new Rectangle(*this);}
public:
    Rectangle()
    {
        type = "Rectangle";
        nSides = 2;
        side1 = 0;
        side2 = 0;
    }
    Rectangle(double s1, double s2)
    {
        type = "Rectanlge";
        nSides = 2;
        side1 = s1;
        side2 = s2;
    }
    double ComputeArea() const {return side1*side2;}
    double ComputePerimeter() const {return 2*(side1+side2);}
};

#endif
