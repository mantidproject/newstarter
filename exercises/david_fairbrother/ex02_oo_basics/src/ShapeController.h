
#ifndef SHAPE_CONTROLLER_H
#define SHAPE_CONTROLLER_H

#include "shapeEnum.h"
#include "Shape.h"

class ShapeController {
public:
	ShapeController(shapes newShape, double width = 0, double height = 0, double radius=0);
	~ShapeController();



private:
	Shape *shapePtr;
};

#endif // !SHAPE_CONTROLLER_H
