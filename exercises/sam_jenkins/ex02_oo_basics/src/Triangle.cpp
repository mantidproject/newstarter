#include "Shapes.h"
#include <ctgmath>
#include "Triangle.h"

	Triangle::Triangle() :Shapes("Triangle", 3), base(1), height(1){}

	Triangle::Triangle(double base, double height) : Shapes("Triangle", 3), base(base) ,height(height)	{}

	double Triangle::calcPerimiter()const {
		return(base + 2 * (sqrt(pow(height, 2) + (pow(base, 2) / 4))));
	}
	double Triangle::calcArea()const {
	
	
		return (base * height)/2;
	}
