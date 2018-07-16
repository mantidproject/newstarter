#include "Rectangle.h"

Rectangle::Rectangle(double width, double height)
    : m_width(width), m_height(height), m_area(width * height),
      m_perimeter(width * 2 + height * 2) {}

/**
* method gets the object width
* @params none
* @return The width
*/
double Rectangle::getWidth() const { return m_width; }

/**
* method gets the object height
* @params none
* @return The height
*/
double Rectangle::getHeight() const { return m_height; }

/**
 * method gets the object type
 * @params none
 * @return A string relating to the objects type
 */
std::string Rectangle::getType() const { return "rectangle"; }

/**
 * method gets the number of sides
 * @params none
 * @return The number of sides
 */
std::size_t Rectangle::getNumberOfEdges() const { return 4; }

/**
 * method gets the shape perimeter
 * @params none
 * @return The perimeter
 */
double Rectangle::getPerimeter() const { return m_perimeter; }

/**
 * method gets the shape area
 * @params none
 * @return The area
 */
double Rectangle::getArea() const { return m_area; }
