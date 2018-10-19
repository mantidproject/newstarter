#pragma once

#include "Shape.h"

class Square : public Shape
{
private:
	double m_side;

public:
	Square(double s);
	double GetPerimeter() const;
	double GetArea() const;
	std::string GetType() const;
	int GetNumSides() const;
	double GetSide() const;
	Square* clone() const;
	std::string GetMessage() const;
};
