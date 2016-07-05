#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <vector>
#include <iostream>

#include "Shape.h"


class ShapeSorter{
public:

	ShapeSorter()
	{
		shapesContainer = new std::vector<Shape*>();
	}
	~ShapeSorter()
	{
		delete shapesContainer;
	}

	/// Add shape to the vector holder
	void addShape(Shape& shape);

	/// Get all shapes from parameter type as text in stdout
	void getShapesFromType(std::string type) const;

	/// Get all shapes with count equal to the parameter as text in stdout
	void getShapesFromSides(int sides) const;

	/// Get the shape's volume(area) in stdout
	void getShapesVolumeDesc() const;

	/// Get the shape's perimeter in stdout
	void getShapesPerimeterDesc() const;

private:
	std::vector<Shape*> * shapesContainer;
};

#endif /* SHAPESORTER_H */