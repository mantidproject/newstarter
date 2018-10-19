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
	std::unique_ptr<Square> square_ptr(new Square(squareSide));

	double recWidth = 2;
	double recHeight = 5;
	std::unique_ptr<Rectangle> rectangle_ptr(new Rectangle(recWidth, recHeight));

	double circleRadius = 5;
	std::unique_ptr<Circle> circle_ptr(new Circle(circleRadius));

	double triangleBase = 3;
	double triangleHeight = 4;
	std::unique_ptr<Triangle> triangle_ptr(new Triangle(triangleBase, triangleHeight));

	// Create a vector and place the shapes in it
	std::vector<std::unique_ptr<Shape>> myShapes;

	myShapes.push_back(std::move(square_ptr));
	myShapes.push_back(std::move(rectangle_ptr));
	myShapes.push_back(std::move(circle_ptr));
	myShapes.push_back(std::move(triangle_ptr));

	// Examine behaviour of the shape sorter
	ShapeSorter shapeSorter = ShapeSorter();
	shapeSorter.PrintBasedOnType(myShapes, "Circle");
	shapeSorter.PrintBasedOnType(myShapes, "Triangle");
	shapeSorter.PrintBasedOnNSides(myShapes, 4);

	shapeSorter.PrintShapes(shapeSorter.SortByAreaDesc(myShapes));
	shapeSorter.PrintShapes(shapeSorter.SortByPerimeterDesc(myShapes));
}

#endif
