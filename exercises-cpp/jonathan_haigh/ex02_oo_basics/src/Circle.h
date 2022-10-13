#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
	Circle(const double radius);

private:
	void calcArea() override;
	void calcPerimeter() override;

	double m_radius;
};