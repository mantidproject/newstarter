#pragma once
#include "Shape.h"



class Circle : public Shape
{
private:
	const double radius;
public:
	Circle(double r) :radius(r) {}
	double find_perimeter() const;
	double find_area() const;
	std::string get_type() const;
	unsigned int get_sides() const;
};
