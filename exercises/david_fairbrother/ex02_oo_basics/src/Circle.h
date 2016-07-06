
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
	Circle(double radius);
	~Circle();

	double getArea() const;
	double getPerimeter() const;

private:
	struct CircleImpl;
	CircleImpl *circleData;


};

#endif