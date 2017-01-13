/**
* main routine
*/
#include <iostream>
#include <vector>
#include <string>

#include "ShapeSorter.h"


std::vector<Shape> creatShapesAndInsertIntoVector()
{
	//making shapes
	const Circle circ(6);
	const Square square(7);
	const Rectangle rect(23.3, 3.2);
	const Triangle tri(5, 7);
	
	std::vector<Shape> shapes;

	//adding shapes to vector
	shapes.push_back(circ);
	shapes.push_back(rect);
	shapes.push_back(square);
	shapes.push_back(tri);

	return shapes;
}

void sortShapes(const ShapeSorter& sorter)
{
	//call desired functions of sorter
	sorter.printShapesThatMatchType("Triangle");
	sorter.printAreasDesc();
	sorter.printPerimeterDesc();
	sorter.printShapesThatMatchNumberOfSides(8);
}

int main(int, char **)
{
	//create a shapeSorter and feed it a populated shape vector
	ShapeSorter sorter(creatShapesAndInsertIntoVector());
	sortShapes(sorter);	
}