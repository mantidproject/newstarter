#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(const double height, const double base);

private:
	void calcArea() override;
	void calcPerimeter() override;

	double m_height;
	double m_base;
};