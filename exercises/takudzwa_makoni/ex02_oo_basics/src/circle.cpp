#include "circle.h"

Circle::Circle(double radius) : m_radius(radius) {};
	 
unsigned int Circle::numOfSides() const  { return m_numOfSides; }
std::string Circle::shapeType() const { return "CIRCLE"; }

double Circle::area() const  { return m_pi * m_radius * m_radius; } //removed override
double Circle::perimeter() const   { return m_pi * 2 * m_radius; }	//removed override



