#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

using namespace std;

class Triangle : public Shape
{
	
private:
   double height;
   double width;

public:
	Triangle(double height, double width);
	double getHeight();
	double getWidth();
	void setHeight(double height);
	void setWidth(double width);
	double getArea()const;
	double getPerimeter()const;
};

#endif