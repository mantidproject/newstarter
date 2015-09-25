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

//----------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------
typedef std::unique_ptr<Shape> ShapeUPtr;
typedef std::vector<ShapeUPtr> ShapeVector;

/**
 *
 */
void PrintAllShapes(const ShapeVector& shapes)
{
	std::cout << "List all available shapes:" << std::endl;
	std::cout << "--------------------------" << std::endl;
	
	for (const auto& shape : shapes)
	{
		std::string column;

		column = "Shape[" + shape->getType() + "]:";
		std::cout << std::setw(20) << std::left << column;

		column = "Sides = " + std::to_string(shape->getSideCount());
		std::cout << std::setw(15) << std::left << column;

		column = "Perim = " + std::to_string(shape->calcPerimeter());
		std::cout << std::setw(20) << std::left << column;

		column = "Area = " + std::to_string(shape->calcArea());
		std::cout << std::setw(20) << std::left << column;

		std::cout << std::endl;
	}

	std::cout << std::endl;
}


/**
 * Main routine
 */
int main(int, char **)
{
	// Create some shapes in a generic vector
	ShapeVector shapes;
	shapes.push_back(ShapeUPtr(new Square(3.0)));
	shapes.push_back(ShapeUPtr(new Rectangle(4.0, 5.0)));
	shapes.push_back(ShapeUPtr(new Circle(4.0)));
	shapes.push_back(ShapeUPtr(new Triangle(6.0, 8.0)));

	// Print shape info to stdout
	PrintAllShapes(shapes);

	system("pause");
}