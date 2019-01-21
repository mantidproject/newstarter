#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	const double side1;
	const double side2;
public:
	Rectangle(double s1, double s2) :side1(s1), side2(s2) {}
	double find_perimeter() const;
	double find_area() const;
	std::string get_type() const;
	unsigned int get_sides() const;
};
