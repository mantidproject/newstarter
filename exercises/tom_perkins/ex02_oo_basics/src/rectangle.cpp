#include "rectangle.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Construct a new Rectangle with given sides x, y
 * \param xIn Length of one side of rectangle
 * \param yIn Length of other side of rectangle
 * \param nameIn Name to give the shape
 */
Rectangle::Rectangle(double xIn, double yIn, std::string nameIn)
    : x(xIn), y(yIn), Shape(4, "rectangle", nameIn) {}

/**
 * \brief Construct a new Rectangle with given sides x, y and type name
 * \param xIn Length of one side of rectangle
 * \param yIn Length of other side of rectangle
 * \param typeIn Name of type of shape e.g. "square"
 * \param nameIn Name to give the shape
 *
 * Intended to be used by derived classes of Rectangle
 *
 */
Rectangle::Rectangle(double xIn, double yIn, std::string nameIn,
                     std::string typeIn)
    : x(xIn), y(yIn), Shape(4, typeIn, nameIn) {}

/**
 * \brief Calculates the perimeter of this rectangle.
 * \returns Perimeter of the rectangle.
 */
double Rectangle::perimeter() const { return x + x + y + y; }

/**
 * \brief Calculates the area of this rectangle.
 * \returns Area of the rectangle.
 */
double Rectangle::area() const { return x * y; }