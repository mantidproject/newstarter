
#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
	Shape(std::string name, int sides);
	virtual ~Shape();

	std::string getName() const;
	int getNumOfSides() const;

	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;

private:
	/* We could use unique_ptr - but for this exercise
	 * practice using new and delete correctly			*/
	struct ShapeImpl;
	ShapeImpl *ShapeData; //PIMPL class

};



#endif
