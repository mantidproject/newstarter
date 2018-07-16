#include "Triangle.h"

#include <cmath>

Triangle::Triangle(double base, double height)
    : m_base(base), m_height(height), m_area(0.5 * base * height),
      m_perimeter(base + 2 * std::sqrt(height * height + (base * base / 4))) {}

/**
 * method gets the object base size
 * @params none
 * @return The base size
 */
double Triangle::getBase() const { return m_base; }

/**
 * method gets the object height
 * @params none
 * @return The base height
 */
double Triangle::getHeight() const { return m_height; }

/**
 * method gets the object type
 * @params none
 * @return A string relating to the objects type
 */
std::string Triangle::getType() const { return "triangle"; }

/**
 * method gets the number of sides
 * @params none
 * @return The number of sides
 */
std::size_t Triangle::getNumberOfEdges() const { return 3; }

/**
 * method gets the shape area
 * @params none
 * @return The area
 */
double Triangle::getArea() const { return m_area; }

/**
 * method gets the shape perimeter
 * @params none
 * @return The perimeter
 */
double Triangle::getPerimeter() const { return m_perimeter; }
