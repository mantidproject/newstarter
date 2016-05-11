#ifndef CLASS_SQUARE
#define CLASS_SQUARE
#include "ShapeBase.h"

class Square: public ShapeBase {
private:
    double side;
protected:
    Square* clone() const {return new Square(*this);}
public:
    Square()
    {
        type = "Square";
        nSides = 4;
        side = 0;
    }
    Square(double s)
    {
        type = "Square";
        nSides = 4;
        side = s;
    }
    double ComputeArea() const {return side*side;}
    double ComputePerimeter() const {return 4*side;}
};

#endif
