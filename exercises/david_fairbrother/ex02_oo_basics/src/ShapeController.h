
#ifndef SHAPE_CONTROLLER_H
#define SHAPE_CONTROLLER_H

#include "shapeEnum.h"
#include "Shape.h"

#include <string>


class ShapeController {
public:
	ShapeController();
	ShapeController(shapes newShape, double width = 0, double height = 0);
	ShapeController(const ShapeController &other);
	~ShapeController();

	void changeShape(shapes newShape, double width = 0, double height = 0);
	bool isSetup() const;

	std::string getShapeName() const;
	shapes getShapeEnum() const;

	int getNoOfSides() const;
	double getShapeWidth() const;
	double getShapeHeight() const;

	double getShapeArea() const;
	double getShapePerimeter() const;

private:
	void setupShape(shapes newShape, double width, double height);

	bool ptrIsSet;
	Shape *shapePtr;
};

#endif // !SHAPE_CONTROLLER_H
