#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"


class Square : public Shape
{
	private:
        double side;

	public:
        Square(double side);
        double GetSide();
        void SetSide(double size);
        double getArea() const;
		double getPerimeter() const;
};

#endif
