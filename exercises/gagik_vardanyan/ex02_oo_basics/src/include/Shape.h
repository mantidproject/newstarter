#ifndef CLASS_SHAPE
#define CLASS_SHAPE
#include <string>

/**
 * An abstract base class for generic shapes
 */

class Shape {

protected:
    std::string type; /**< type of the shape*/
    int nSides; /**< number of sides*/

    ///default constructor
    Shape() : type(""), nSides(0) {}

public:
    ///virtual clone function
    ///@return a pointer to the new object of the same type
    virtual Shape* clone() const = 0;

    ///getter for number of sides
    /// @return number of sides
    double GetNSides() const {return nSides;}

    ///getter for the type
    /// @return the type of the shape
    std::string GetType() const {return type;}

    ///virtual function for computing the area
    /// @return the area of the shape
    virtual double ComputeArea() const = 0;

    ///virtual function for computing the perimeter
    /// @return the perimeter of the shape
    virtual double ComputePerimeter() const = 0;

    ///virtual distructor
    virtual ~Shape() {}

    ///static binary predicate for area comparison
    /// @param sh1 shape object
    /// @param sh2 shape object
    /// @return True if the sh1 has larger area, False otherwise
    static bool CompareArea(const Shape* sh1, const Shape* sh2) {
        return sh1->ComputeArea() > sh2->ComputeArea();
    }

    ///static binary predicate for perimeter comparison
    /// @param sh1 shape object
    /// @param sh2 shape object
    /// @return True if the sh1 has larger perimeter, False otherwise
    static bool ComparePerimeter(const Shape* sh1, const Shape* sh2) {
        return sh1->ComputePerimeter() > sh2->ComputePerimeter();
    }
};

#endif
