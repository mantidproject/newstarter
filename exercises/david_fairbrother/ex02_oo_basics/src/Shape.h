
#ifndef SHAPE_H
#define SHAPE_H

#include "shapeEnum.h"

#include <string>

class Shape
{
public:
	Shape(std::string name, int sides, ShapesEnum shapeEnum, double width = 0, double height = 0);
	virtual ~Shape();

	std::string getName() const;
	int getNumOfSides() const;
	ShapesEnum getShapeEnum() const;

	double getShapeHeight() const;
	double getShapeWidth() const;

	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;

private:
	/* We could use unique_ptr - but for this exercise
	 * practice using new and delete correctly			*/
	struct ShapeImpl;
	ShapeImpl *ShapeData; //PIMPL class

};



#endif
