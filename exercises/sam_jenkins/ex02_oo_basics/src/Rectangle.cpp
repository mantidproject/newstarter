#include "Shapes.h"
class Rectangle : public Shapes {
public:
	Rectangle() :side1(1),side2(2)
	{
		type = "Rectangle";
		sides = 4;

	}
	Rectangle(double side1,double side2) :side1(side1),side2(side2)
	{
		type = "Rectangle";
		sides = 4;

	}
	double calcPerimiter() {
		return (2 * side1) + (2* side2);
	}
	double calcArea() {
		return side1*side2;
	}
private:
	double side1;
	double side2;
};