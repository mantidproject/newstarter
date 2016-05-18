/*!
* A class to define a rectangle
*/

#ifndef CLASS_RECTANGLE
#define CLASS_RECTANGLE
#include "Shape.h"

class Rectangle: public Shape {
private:
    double side1; /**< side 1 */
    double side2; /**< side 2 */

public:
    ///clone function
    /// @return new rectangle object
    Rectangle* clone() const {return new Rectangle(*this);}

    ///default constructor
    Rectangle()
    {
        type = "Rectangle";
        nSides = 4;
        side1 = 0;
        side2 = 0;
    }

    ///constructor from sides
    /// @param s1 side1
    /// @param s2 side2
    Rectangle(double s1, double s2)
    {
        type = "Rectanlge";
        nSides = 4;
        side1 = s1;
        side2 = s2;
    }

    ///computes the area
    /// @return the area
    double ComputeArea() const {return side1*side2;}

    ///computes the perimeter
    /// @return the perimeter
    double ComputePerimeter() const {return 2*(side1+side2);}
};

#endif
