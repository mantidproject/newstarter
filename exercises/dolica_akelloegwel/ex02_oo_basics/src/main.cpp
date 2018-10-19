#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"

#ifndef _Shape_h
#define _Shape_h

int main(int, char **)
{
	// Create various shapes
	double squareSide = 2.5;

	double recWidth = 2;
	double recHeight = 5;

	double circleRadius = 5;

	double triangleBase = 3;
	double triangleHeight = 4;

	// Create a vector and place the shapes in it
	std::vector<std::unique_ptr<Shape>> myShapes;

	myShapes.push_back(std::make_unique<Square>(squareSide));
	myShapes.push_back(std::make_unique<Rectangle>(recWidth,recHeight));
	myShapes.push_back(std::make_unique<Circle>(circleRadius));
	myShapes.push_back(std::make_unique<Triangle>(triangleBase, triangleHeight));

	// Examine behaviour of the shape sorter
	ShapeSorter shapeSorter = ShapeSorter();
	shapeSorter.PrintBasedOnType(myShapes, "Circle");
	shapeSorter.PrintBasedOnType(myShapes, "Triangle");
	shapeSorter.PrintBasedOnNSides(myShapes, 4);

	shapeSorter.PrintShapes(shapeSorter.SortByAreaDesc(myShapes));
	shapeSorter.PrintShapes(shapeSorter.SortByPerimeterDesc(myShapes));
}

#endif
