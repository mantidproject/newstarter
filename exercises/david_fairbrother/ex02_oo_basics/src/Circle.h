
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "shapeEnum.h"

class Circle : public Shape {
public:
	Circle(double radius, ShapesEnum shapeEnum);
	~Circle();

	double getArea() const;
	double getPerimeter() const;

private:
	struct CircleImpl;
	CircleImpl *circleData;


};

#endif