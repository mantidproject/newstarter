#include "Circle.h"

Circle::Circle(double radius) : Shape()
{
	// Set the radius
	m_radius = radius;
}
double Circle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}
double Circle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}
std::string Circle::GetType() const
{
	return "Circle";
}
int Circle::GetNumSides() const
{
	return 1;
}
double Circle::GetRadius() const
{
	return m_radius;
}
Circle* Circle::clone() const
{
	return new Circle(*this);
}
std::string Circle::GetMessage() const
{
	// Construct a message for use when overloading <<
	std::string circleMessage = "Circle Properties: \n";
	circleMessage += "  Radius: " + std::to_string(m_radius);
	circleMessage += CreateBaseMessage(GetPerimeter(),GetArea());
	return circleMessage;
}
