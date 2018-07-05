#include "Shapes.h"
#include <ctgmath>
class Triangle : public Shapes {
public:
	Triangle() :base(1), height(1)
	{
		type = "Triangle";
		sides = 3;
	}
	Triangle(double base, double height) :base(base)
	{
		type = "Triangle";
		sides = 3;
	}
	double calcPerimiter() const{
		return(base + 2 * (sqrt(pow(height, 2) + (pow(base, 2) / 4))));
	}
	double calcArea() const{
		return (base*height)/2;
	}
private:
	double height;
	double base;
};