#include "circle.h"
#include <cmath>

/**
 * @brief Construct a new Circle:: Circle object
 *
 * @param r Radius of circle.
 */
Circle::Circle(int r) : Shape(1, "Circle"), m_radius(r) {}

/**
 * @brief Calculate area of circle
 * (pi*r)^2
 *
 * @return double
 */
double Circle::area() const { return M_PI * pow(m_radius, 2); }

/**
 * @brief Calculate perimiter of a circle
 * (2*pi*r)
 *
 * @return double
 */
double Circle::perimiter() const { return 2 * M_PI * m_radius; }