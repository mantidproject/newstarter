#ifndef GUARD_Rectangle_h
#define GUARD_Rectangle_h
#include "Shapes.h"

class Rectangle : public Shapes {

public:
	Rectangle();
	Rectangle(double side1,double side2);
	double calcPerimiter()const;
	double calcArea()const;

private:
	double side1;
	double side2;
};




#endif
