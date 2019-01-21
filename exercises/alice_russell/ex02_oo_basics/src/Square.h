#pragma once
#include "Shape.h"

class Square : public Shape
{
private:
	const double side;
public:
	Square(double side1):side(side1) {}
	double find_perimeter() const ;
	double find_area() const ;
	std::string get_type() const;
	unsigned int get_sides() const;
};

