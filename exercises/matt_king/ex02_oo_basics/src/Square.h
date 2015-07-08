/**
*  Contains methods whose bodies are contained in Square.cpp
*/

#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape
{
public:
	Square();
	Square(double side);
	~Square(){};
	double calculateArea();
	double calculatePerimeter();
	double getSide();
private:
	double side;
};

#endif //Square.h