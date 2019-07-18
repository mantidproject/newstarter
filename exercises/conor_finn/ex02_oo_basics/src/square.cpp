#include "square.h"

/**
 * @brief Construct a new Square:: Square object
 *
 * @param s The side length of the square.
 */
Square::Square(int s) : Shape(4, "Square"), m_side1(s) {}

/**
 * @brief Calculate the perimiter.
 *
 * @return double Perimiter result.
 */
double Square::perimiter() const { return m_side1 * 4; }

/**
 * @brief Calculate the area.
 *
 * @return double Area result.
 */
double Square::area() const { return m_side1 * m_side1; }