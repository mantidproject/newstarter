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
	//making shapes
	Circle circ(6);
	Square square(7);
	Rectangle rect(23.3, 3.2);
	Triangle tri(5, 7);
	
	std::vector<Shape> shapes;

	//adding shapes to vector
	shapes.push_back(circ);
	shapes.push_back(rect);
	shapes.push_back(square);
	shapes.push_back(tri);

	//create a shapeSorter and feed it shapes
	ShapeSorter sorter(shapes);

	//call desired functions of sorter
	sorter.printShapesThatMatchType("Triangle");
	sorter.printAreasDesc();
	sorter.printPerimeterDesc();
	sorter.printShapesThatMatchNumberOfSides(8);
	
	
	
}