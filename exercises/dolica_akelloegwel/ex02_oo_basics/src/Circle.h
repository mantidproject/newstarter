#pragma once

#include "Shape.h"

class Circle : public Shape
{
private:
	double m_radius;

public:
	Circle(double r);
	double GetPerimeter() const;
	double GetArea() const;
	std::string GetType() const;
	int GetNumSides() const;
	double GetRadius() const;
	Circle* clone() const;
	std::string GetMessage() const;
};
