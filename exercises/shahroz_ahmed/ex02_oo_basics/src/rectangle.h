#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
using namespace std;

class Rectangle : public Shape
{
	private:
        double width;
		double height;

	public:
        Rectangle(double width, double height);
        double GetWidth();
		double GetHeight();
        void SetWidth(double width);
		void SetHeight(double height);
        double getArea() const;
		double getPerimeter() const;
};

#endif