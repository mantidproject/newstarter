#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
	
private:
   double radius;

public:
	Circle(double radius);
	double getRadius();
	void setRadius(double radius);
	double getArea()const;
	double getPerimeter() const;

};

#endif