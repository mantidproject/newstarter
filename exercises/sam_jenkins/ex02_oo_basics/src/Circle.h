#ifndef GUARD_Circle_h
#define GUARD_Circle_h
#include "Shapes.h"

class Circle : public Shapes {

public:
	Circle();
	Circle(double radius);
	double calcPerimiter()const;
	double calcArea()const;

private:
	double radius;
};




#endif

