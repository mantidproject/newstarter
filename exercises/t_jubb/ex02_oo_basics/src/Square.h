#ifndef HEADER_SQUARE
#define HEADER_SQUARE

#include "Shape.h"

/*
Square class
*/
class Square : public Shape {

public:
	Square(double h);
	double area() ;
	double perimeter();

private:
	double height;
};



#endif