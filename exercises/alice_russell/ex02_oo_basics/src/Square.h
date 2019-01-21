#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"

class Square : public Shape
{
private:
	const double side;
public:
	Square(double side1):side(side1) {}
	double perimeter() const override;
	double area() const override;
	std::string type() const override;
	unsigned int sides() const override;
};

#endif //SQUARE_H_