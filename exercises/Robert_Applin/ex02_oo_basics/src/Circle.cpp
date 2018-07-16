#include "Circle.h"

#include <cmath>

Circle::Circle(double radius)
    : m_radius(radius), m_area(M_PI * radius * radius),
      m_perimeter(2.0 * M_PI * radius) {}

/**
 * method gets the object type
 * @params none
 * @return A string relating to the objects type
 */
std::string Circle::getType() const { return "circle"; }

/**
 * method gets the number of sides
 * @params none
 * @return The number of sides
 */
std::size_t Circle::getNumberOfEdges() const { return 1; }

/**
 * method gets the shape perimeter
 * @params none
 * @return The perimeter
 */
double Circle::getPerimeter() const { return m_perimeter; }

/**
 * method gets the shape area
 * @params none
 * @return The area
 */
double Circle::getArea() const { return m_area; }
