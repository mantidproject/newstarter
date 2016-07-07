
#ifndef SHAPE_CONTROLLER_H
#define SHAPE_CONTROLLER_H

#include "shapeEnum.h"
#include "Shape.h"

#include <string>


class ShapeController {
public:
	ShapeController(ShapesEnum newShape, double width = 0, double height = 0);
	~ShapeController();

	ShapeController(const ShapeController &other);
	ShapeController& operator=(const ShapeController &other);

	//Constructs a new shape held by the shape controller
	void changeShape(ShapesEnum newShape, double width = 0, double height = 0);

	std::string getShapeName() const;
	ShapesEnum getShapeEnum() const;

	int getNoOfSides() const;
	double getShapeWidth() const;
	double getShapeHeight() const;

	double getShapeArea() const;
	double getShapePerimeter() const;

private:
	//Constructs a new shape with the specified parameters
	void setupShape(ShapesEnum newShape, double width, double height);

	Shape *shapePtr;
};

#endif // !SHAPE_CONTROLLER_H
