
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(double base, double height);
	~Triangle();

	double getArea() const;
	double getPerimeter() const;

private:
	struct TriangleImpl;
	TriangleImpl *triangleData;
};

#endif