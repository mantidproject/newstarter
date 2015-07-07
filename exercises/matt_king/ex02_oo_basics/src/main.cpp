/**
* Skeleton main routine
*/
#include <iostream>
#include <vector>
#include <string>

#include "ShapeSorter.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

int main(int, char **)
{
	//Circle circle("Circle", 5);
	//Square square("Square", 3);
	//new Rectangle("Rectangle", 7, 2);
	Circle circ(2);
	Square square(7);
	Rectangle rect(23.3, 3.2);
	Triangle tri(5, 7);
	
	std::vector<Shape> shapes;

	shapes.push_back(circ);
	shapes.push_back(rect);
	shapes.push_back(square);
	shapes.push_back(tri);

	ShapeSorter sorter(shapes);
	sorter.printShapesThatMatchType("Circle");
	sorter.printAreasDesc();
	sorter.printPerimeterDesc();
	sorter.printShapesThatMatchNumberOfSides(4);
	
	
	
}