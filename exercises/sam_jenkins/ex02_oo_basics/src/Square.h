#ifndef GUARD_Square_h
#define GUARD_Square_h
#include "Shapes.h"

class Square : public Shapes {

public:
	Square();
	Square(double length);
	double calcPerimiter()const;
	double calcArea()const;

private:
	double length;
};




#endif
