// BaseShape class implementation
#include "../include/Shapes.h"

/** Constructor
 * Empty constructor
 */
BaseShape::BaseShape(){};
/** Getter for area
 * @return : Returns area of the shape
 */
double BaseShape::getArea() const{
    return this->m_area;
}
/** Getter for perimeter
 * @return : Returns perimeter of the shape
 */
double BaseShape::getPerimeter() const
{
    return this->m_perimeter;
}