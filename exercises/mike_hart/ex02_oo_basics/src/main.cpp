//----------------------------------------------------------------------
// Library Includes
//----------------------------------------------------------------------
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>

//----------------------------------------------------------------------
// Local Includes
//----------------------------------------------------------------------
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "shapesorter.h"



/**
 * Main routine
 */
int main(int, char **)
{
	// Create some shapes in a generic vector
	auto shapes = std::make_shared<ShapeVector>();
	shapes->emplace_back(new Square(3.0));
	shapes->emplace_back(new Rectangle(1.0, 20.0));
	shapes->emplace_back(new Circle(4.0));
	shapes->emplace_back(new Triangle(3.0, 14.0));
	shapes->emplace_back(new Square(7.5));

	// Create ShapeSorter that operates on our shape vector
	ShapeSorter sorter(shapes);

	// Test member functions
	sorter.printByTypeMatch("Square");
	sorter.printByTypeMatch("Circle");
	sorter.printBySideCount(2);
	sorter.printBySideCount(3);
	sorter.printBySideCount(4);
	sorter.printByArea();
	sorter.printByPerimeter();

	system("pause");
}
