#include "square.h"


Square::Square(double length) : m_length(length) {};

unsigned int Square::numOfSides() const { return Square::m_numOfSides ; }
std::string Square::shapeType() const { return "SQUARE"; }

double Square::area() const  { return Square::m_length * m_length; }
double Square::perimeter() const  { return 4 * m_length; }


	