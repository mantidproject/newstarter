#ifndef RECTANGLE_H
#define	RECTANGLE_H
/********************************INCLUDES***********************************/
#include "Shape.h"

/*******************************CLASS HEADER********************************/
class Rectangle : public Shape{
public:
	Rectangle();
	Rectangle(double h, double w);
	~Rectangle();
	void print();
private:

};

/**********************************END OF FILE******************************/

#endif RECTANGLE_H