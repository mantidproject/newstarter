#include "Shapes.h"
class Square : public Shapes {
public:
	Square() :side(1) 
	{
		type = "Square";
		sides = 4;
	}
	Square(double side):side(side)
	{
		type = "Square";
		sides = 4;
	}
	double calcPerimiter() {
		return 4 * side;
	}
	double calcArea() {
		return side*side;
	}
private:
	double side;
	
};