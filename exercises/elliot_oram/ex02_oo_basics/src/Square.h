#ifndef SQUARE_H
#define	SQUARE_H
/********************************INCLUDES***********************************/
#include "Shape.h"

/*******************************CLASS HEADER********************************/
class Square : public Shape{
public:
	Square();
	Square(double h, double w);
	~Square();
	void print();
private:

};

/**********************************END OF FILE******************************/

#endif SQUARE_H 