#include "rectangle.h"

Rectangle::Rectangle(double width, double height) : m_sideWidth(width), m_sideHeight(height) {};

unsigned int Rectangle::numOfSides() const { return Rectangle::m_numOfSides; }
std::string Rectangle::shapeType() const { return "RECTANGLE"; }

double Rectangle::area() const  { return m_sideHeight * m_sideWidth; }
double Rectangle::perimeter() const  { return (2 * m_sideWidth) + (2 * m_sideHeight); }



