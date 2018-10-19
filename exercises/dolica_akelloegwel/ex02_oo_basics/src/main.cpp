#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"

#ifndef _Shape_h
#define _Shape_h

int main(int, char **)
{
	// Create a vector and place the shapes in it
	std::vector<ShapeSorter::Shape_cuptr> myShapes;

	myShapes.push_back(std::make_unique<Square>(2.5 /* squareSide */));
	myShapes.push_back(std::make_unique<Rectangle>(2 /* recWidth */, 5 /* recHeight */));
	myShapes.push_back(std::make_unique<Circle>(5 /* circleRadius */));
	myShapes.push_back(std::make_unique<Triangle>(3 /* triangleBase */, 4 /* triangleHeight */));

	// Examine behaviour of the shape sorter
	ShapeSorter shapeSorter = ShapeSorter();
	shapeSorter.PrintBasedOnType(myShapes, "Circle");
	shapeSorter.PrintBasedOnType(myShapes, "Triangle");
	shapeSorter.PrintBasedOnNSides(myShapes, 4);

	shapeSorter.PrintShapes(shapeSorter.SortByAreaDesc(myShapes));
	shapeSorter.PrintShapes(shapeSorter.SortByPerimeterDesc(myShapes));
}

#endif
