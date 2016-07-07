
#ifndef SHAPE_CONTROLLER_H
#define SHAPE_CONTROLLER_H

#include "shapeEnum.h"
#include "Shape.h"

#include <string>


class ShapeController {
public:
	ShapeController();
	ShapeController(ShapesEnum newShape, double width = 0, double height = 0);
	ShapeController(const ShapeController &other);
	~ShapeController();
	ShapeController& operator=(const ShapeController &other);


	void changeShape(ShapesEnum newShape, double width = 0, double height = 0);
	bool isSetup() const { return ptrIsSet; }

	std::string getShapeName() const;
	ShapesEnum getShapeEnum() const;

	int getNoOfSides() const;
	double getShapeWidth() const;
	double getShapeHeight() const;

	double getShapeArea() const;
	double getShapePerimeter() const;

private:
	void setupShape(ShapesEnum newShape, double width, double height);

	bool ptrIsSet;
	Shape *shapePtr;
};

#endif // !SHAPE_CONTROLLER_H
