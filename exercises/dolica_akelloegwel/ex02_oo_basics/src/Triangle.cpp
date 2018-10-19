#include "Triangle.h"

Triangle::Triangle(double base, double height) : Shape()
{
	// Set the base and height values
	m_base = base;
	m_height = height;
}
double Triangle::GetPerimeter() const
{
	return m_base + 2 * std::sqrt(m_height * m_height + m_base * m_base * 0.25);
}
double Triangle::GetArea() const
{
	return m_base * 0.5 * m_height;
}
std::string Triangle::GetType() const
{
	return "Triangle";
}
int Triangle::GetNumSides() const
{
	return 3;
}
double Triangle::GetBase() const
{
	return m_base;
}
double Triangle::GetHeight() const
{
	return m_height;
}
Triangle* Triangle::clone() const
{
	return new Triangle(*this);
}
std::string Triangle::GetMessage() const
{
	// Construct and set a message for use when overloading <<
	std::string triangleMessage = "Triangle Properties:\n";
	triangleMessage += "  Base: " + std::to_string(m_base) + "\n";
	triangleMessage += "  Height: " + std::to_string(m_height);
	triangleMessage += CreateBaseMessage(GetPerimeter(),GetArea());
	return triangleMessage;
}
