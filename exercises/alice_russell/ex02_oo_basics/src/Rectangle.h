#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape
{
private:
	const double side1;
	const double side2;
public:
	Rectangle(double s1, double s2) :side1(s1), side2(s2) {}
	double perimeter() const override;
	double area() const override;
	std::string type() const override;
	unsigned int sides() const override;
};

#endif //RECTANGLE_H_