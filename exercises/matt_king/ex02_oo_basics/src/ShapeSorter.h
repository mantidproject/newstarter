#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "Shape.h"

#include <vector>

class ShapeSorter{
public:
	ShapeSorter(const std::vector<Shape>& shapes);
	std::vector<Shape> getShapes() const;
	int printShapesThatMatchType(const std::string& type) const;
	int printShapesThatMatchNumberOfSides(int numberOfSides) const;
	int printAreasDesc() const;
	int printPerimeterDesc() const;
private:
	std::vector<Shape> shapesToSort;

};
#endif // !SHAPESORTER_H