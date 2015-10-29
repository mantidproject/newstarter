#include <iostream>
#include <vector>
#include <memory>
#include "circle.h"
#include "triangle.h"
#include "square.h"

/**
 * Shape: Create a selection of shapes in a vector.
 * Use these to test the ShapeSorter's methods.
 */
int main(int argc, char ** argv)
{
	// Create shapes and put them in a vector
	std::vector<std::shared_ptr<Shape> > shapes;
	shapes.push_back(std::make_shared<Circle>(1.0));
	shapes.push_back(std::make_shared<Triangle>(1.0, 1.0));
	shapes.push_back(std::make_shared<Rectangle>(1.0, 2.0));
	shapes.push_back(std::make_shared<Square>(1.0));

	for (auto iter = shapes.begin(); iter != shapes.end(); iter++)
	{
		std::cout << (*iter)->type << std::endl;
	}

	return 0;
}