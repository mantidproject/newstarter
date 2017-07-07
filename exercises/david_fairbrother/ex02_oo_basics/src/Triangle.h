
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "shapeEnum.h"

class Triangle : public Shape {
public:
	Triangle(double base, double height, ShapesEnum shapeEnum);
	~Triangle();

	double getArea() const;
	double getPerimeter() const;

private:
	struct TriangleImpl;
	TriangleImpl *triangleData;
};

#endif