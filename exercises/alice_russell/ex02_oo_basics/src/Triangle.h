#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape
{
private:
	const double height;
	const double base;
public:
	Triangle(double h, double b):height(h), base(b) {}
	double perimeter() const override;
	double area() const override;
	std::string type() const override;
	unsigned int sides() const override;
};

#endif //TRIANGLE_H_