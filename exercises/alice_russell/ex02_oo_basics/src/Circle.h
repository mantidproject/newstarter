#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <cmath>
#include "Shape.h"

class Circle : public Shape
{
private:
	const double radius;
public:
	Circle(double r) :radius(r) {}
	double perimeter() const override;
	double area() const override;
	std::string type() const override;
	unsigned int sides() const override;
};

#endif //CIRCLE_H_