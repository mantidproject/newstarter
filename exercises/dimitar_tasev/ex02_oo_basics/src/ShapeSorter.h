#ifndef SHAPESORTER_H
#define SHAPESORTER_H


//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------

#include <vector>
#include <iostream>
#include <algorithm>

#include "Shape.h"
#include <memory>


class ShapeSorter{
public:

	ShapeSorter(): m_shapesContainer(new std::vector<Shape*>())
	{
	}

	~ShapeSorter()
	{
		m_shapesContainer.release();
	}

	/// Add shape to the vector holder
	void addShape(Shape &shape);

	/// Get all shapes from parameter type as text in stdout
	void getShapesFromType(std::string type) const;

	/// Get all shapes with count equal to the parameter as text in stdout
	void getShapesFromSides(int sides) const;

	/// Get the shape's volume(area) in stdout
	void getShapesVolumeDesc() const;

	/// Get the shape's perimeter in stdout
	void getShapesPerimeterDesc() const;

private:
	std::unique_ptr<std::vector<Shape*>> m_shapesContainer;
};

#endif /* SHAPESORTER_H */
