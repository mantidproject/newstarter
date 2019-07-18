#include "triangle.h"
#include <cmath>

/**
 * @brief Construct a new Triangle:: Triangle object
 *
 * @param h Height of triangle.
 * @param b Base of triangle.
 */
Triangle::Triangle(int h, int b)
    : Shape(3, "Triangle"), m_height(h), m_base(b) {}

/**
 * @brief Calculate perimiter.
 *
 * @return double Perimiter of triangle.
 */
double Triangle::perimiter() const {
  return (m_base + (2 * (sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4)))));
}

/**
 * @brief Calculate area.
 *
 * @return double Area of triangle.
 */
double Triangle::area() const { return (m_base * m_height) / 2; }