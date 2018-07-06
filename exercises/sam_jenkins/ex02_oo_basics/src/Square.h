#ifndef GUARD_Square_h
#define GUARD_Square_h
#include "Shapes.h"
class Square : public Shapes {
public:
	Square();
	Square(double side);
	double calcPerimiter()const;
	double calcArea()const;
private:
	double side;
};




#endif
