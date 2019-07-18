#include "shape.h"
#include <iostream>

/**
 * @brief Construct a new Shape:: Shape object
 *
 * @param s Number of sides.
 * @param n Name of shape.
 */
Shape::Shape(int s, std::string n) : m_sides(s), m_name(n) {}

/**
 * @brief Accessor method for number of sides.
 *
 * @return int Number of sides.
 */
int Shape::getNumberOfSides() const { return m_sides; }

/**
 * @brief Accessor method for shape name.
 *
 * @return std::string Name of shape.
 */
std::string Shape::getName() const { return m_name; }

/**
 * @brief Prints some of the information about a shape.
 *
 */
void Shape::printInfo() const {
  std::cout << "  This shape is a " << m_name << ".\n"
            << "  It has a perimiter of: " << perimiter()
            << ", and an area of: " << area() << "\n";
}