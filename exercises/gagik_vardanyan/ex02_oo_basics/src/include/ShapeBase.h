#ifndef CLASS_SHAPEBASE
#define CLASS_SHAPEBASE
#include <string>

/**
 * An abstract base class for generic shapes
 */

class ShapeBase {
    friend class Shape;
protected:
    std::string type; /**< type of the shape*/
    int nSides; /**< number of sides*/

    ///virtual clone function
    ///@return a pointer to the new object of the same type
    virtual ShapeBase* clone() const {return new ShapeBase(*this);}
public:
    ///default constructor
    ShapeBase() : type(""), nSides(0) {}

    ///getter for number of sides
    /// @return number of sides
    double GetNSides() const {return nSides;}

    ///getter for the type
    /// @return the type of the shape
    std::string GetType() const {return type;}

    ///virtual function for computing the area
    /// @return the area of the shape
    virtual double ComputeArea() const {return 0;}

    ///virtual function for computing the perimeter
    /// @return the perimeter of the shape
    virtual double ComputePerimeter() const {return 0;}

    ///virtual distructor
    virtual ~ShapeBase() {}
};

#endif
