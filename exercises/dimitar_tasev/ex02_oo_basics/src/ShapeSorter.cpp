#include "ShapeSorter.h"
#include <algorithm>

/** Adds a shape to the container
*
*/
void ShapeSorter::addShape(Shape& shape)
{
	shapesContainer->push_back(&shape);
}

/** Print the shapes that have the same type
*/
void ShapeSorter::getShapesFromType(std::string type) const
{
	std::cout << "Searching for shapes of type " << type << '.' << std::endl;

	int count = 0;
	for (auto itr = shapesContainer->begin(); itr != shapesContainer->end(); ++itr)
	{
		if (type == (*itr)->getType())
		{
			count++;

			// Determine the suffix of the number
			// P.S. Nesting ternary operations is a bad idea
			std::cout << "Found a " << (*itr)->getType() << " shape, this is the " << count
				<< (count % 10 == 1 ? "st" : count % 10 == 2 ? "nd" : count % 10 == 3 ? "rd" : "th")
				<< " that I've found! It has volume(area) of " << (*itr)->getVolume()
				<< " and perimeter of " << (*itr)->getPerimeter() << " and " << (*itr)->getSides() << " sides." << std::endl;
		}
	}
}

/** Prints all shapes that have the same amount of sides
*
*/
void ShapeSorter::getShapesFromSides(int sides) const
{
	std::cout << "Searching for shapes with " << sides << " sides." << std::endl;


	int count = 0;
	for (auto itr = shapesContainer->begin(); itr != shapesContainer->end(); ++itr)
	{
		if (sides == (*itr)->getSides())
		{
			count++;

			// Determine the suffix of the number
			// P.S. Nesting ternary operations is a bad idea
			std::cout << "Found a " << (*itr)->getType() << " shape, this is the " << count
				<< (count % 10 == 1 ? "st" : count % 10 == 2 ? "nd" : count % 10 == 3 ? "rd" : "th")
				<< " that I've found! It has volume(area) of " << (*itr)->getVolume()
				<< " and perimeter of " << (*itr)->getPerimeter() << std::endl;
		}
	}
}

/** Prints all shapes sorted by volume in descending order
 *
 */
void ShapeSorter::getShapesVolumeDesc() const
{
	std::sort(shapesContainer->begin(), shapesContainer->end(),
	          [=](Shape* shape1, Shape* shape2)
	          {
		          return shape1->getVolume() < shape2->getVolume();
	          }
	);

	std::for_each(shapesContainer->begin(), shapesContainer->end(), [](Shape* shape)
	              {
		              std::cout << "Shape " << shape->getType() << " with volume: " << shape->getVolume() << std::endl;;
	              });
}

/** Prints all shapes sorted by perimeter in descending order
*
*/
void ShapeSorter::getShapesPerimeterDesc() const
{
	std::sort(shapesContainer->begin(), shapesContainer->end(),
	          [=](Shape* shape1, Shape* shape2)
	          {
		          return shape1->getPerimeter() < shape2->getPerimeter();
	          }
	);

	std::for_each(shapesContainer->begin(), shapesContainer->end(), [](Shape* shape)
	              {
		              std::cout << "Shape " << shape->getType() << " with perimeter: " << shape->getPerimeter() << std::endl;
	              });
}
