#include "isoTriangle.h"


IsoTriangle::IsoTriangle(double base, double height) : m_base(base), m_height(height) {};

unsigned int IsoTriangle::numOfSides() const { return m_numOfSides; }
std::string IsoTriangle::shapeType() const { return "ISOSCELES-TRIANGLE"; }

double IsoTriangle::area() const  { return 0.5 * m_base* m_height; }
double IsoTriangle::perimeter() const  { return 2 * (sqrt(m_height * m_height) + ((m_base * m_base) / 4)); }


	