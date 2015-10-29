#include <iostream>
#include <vector>
#include <memory>
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include "shapesorter.h"

/**
 * Shape: Create a selection of shapes in a vector.
 * Use these to test the ShapeSorter's methods.
 */
int main(int argc, char ** argv)
{
	// Create shapes and put them in a vector
	std::vector<std::shared_ptr<Shape> > shapes;
	shapes.push_back(std::make_shared<Circle>(1.0, "circle1"));
	shapes.push_back(std::make_shared<Triangle>(1.0, 1.0, "triangle1"));
	shapes.push_back(std::make_shared<Triangle>(3.0, 3.0, "triangle2"));
	shapes.push_back(std::make_shared<Rectangle>(1.0, 2.0, "rect1"));
	shapes.push_back(std::make_shared<Square>(1.0, "square1"));

	// Check that we have the correct shapes in the vector
	std::cout << "Shapes in vector are:" << std::endl;
	for (auto iter = shapes.begin(); iter != shapes.end(); iter++)
	{
		std::cout << (*iter)->name << ": " << (*iter)->type << std::endl;
	}
	
	ShapeSorter sorter;
	auto triangles = sorter.selectByType(shapes, "Triangle");
	std::cout << std::endl << "Triangles are: " << std::endl;
	for (auto iter = triangles.begin(); iter != triangles.end(); iter++)
	{
		std::cout << (*iter)->name << std::endl;
	}
	

	return 0;
}