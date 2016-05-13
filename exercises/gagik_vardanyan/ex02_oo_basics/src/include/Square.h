/*!
* A class to define a square
*/

#ifndef CLASS_SQUARE
#define CLASS_SQUARE
#include "ShapeBase.h"

class Square: public ShapeBase {
private:
    double side; /**< side of the square */

protected:
    ///clone function
    /// @return new square object
    Square* clone() const {return new Square(*this);}

public:
    ///default constructor
    Square()
    {
        type = "Square";
        nSides = 4;
        side = 0;
    }

    ///constructor from side
    /// @param s side of the square
    Square(double s)
    {
        type = "Square";
        nSides = 4;
        side = s;
    }

    ///computes the area
    /// @return the area
    double ComputeArea() const {return side*side;}

    ///computes the perimeter
    /// @return the perimeter
    double ComputePerimeter() const {return 4*side;}
};

#endif
