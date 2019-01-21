#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
	const double height;
	const double base;
public:
	Triangle(double h, double b):height(h), base(b) {}
	double find_perimeter() const;
	double find_area() const;
	std::string get_type() const;
	unsigned int get_sides() const;
};
