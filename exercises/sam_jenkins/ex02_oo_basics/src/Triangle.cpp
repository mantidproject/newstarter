#include "Shapes.h"
#include <ctgmath>
#include "Triangle.h"

	Triangle::Triangle() :base(1), height(1)
	{
		type = "Triangle";
		sides = 3;
	}
	Triangle::Triangle(double base, double height) :base(base) ,height(height)
	{
		type = "Triangle";
		sides = 3;
	}
	double Triangle::calcPerimiter()const {
		return(base + 2 * (sqrt(pow(height, 2) + (pow(base, 2) / 4))));
	}
	double Triangle::calcArea()const {
	
	
		return (base * height)/2;
	}
