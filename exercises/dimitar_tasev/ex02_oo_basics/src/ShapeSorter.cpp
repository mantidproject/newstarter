#include "ShapeSorter.h"

/** Adds a shape to the container
 *
 *	@param shape The shape that will be added to the vector container
 */
void ShapeSorter::addShape(Shape& shape)
{
	m_shapesContainer->push_back(&shape);
}

/** Print the shapes that have the same type
 *
 *	@param type The type of shape that will be looked up 
 */
void ShapeSorter::getShapesFromType(std::string type) const
{
	std::cout << "Searching for shapes of type " << type << '.' << std::endl;

	int shapesCount = 0;
	for (auto itr = m_shapesContainer->begin(); itr != m_shapesContainer->end(); ++itr)
	{
		if (type == (*itr)->getType())
		{
			shapesCount++;

			// Determine the suffix of the number
			// P.S. Nesting ternary operations is a bad idea
			std::cout << "Found a " << (*itr)->getType() << " shape, this is the " << shapesCount
				<< (shapesCount % 10 == 1 ? "st" : shapesCount % 10 == 2 ? "nd" : shapesCount % 10 == 3 ? "rd" : "th")
				<< " that I've found! It has volume(area) of " << (*itr)->getVolume()
				<< " and perimeter of " << (*itr)->getPerimeter() << " and " << (*itr)->getSides() << " sides." << std::endl;
		}
	}
}

/** Prints all shapes that have the same amount of sides
 *
 *	@param sides The number of sides that will be looked up
 */
void ShapeSorter::getShapesFromSides(int sides) const
{
	std::cout << "Searching for shapes with " << sides << " sides." << std::endl;


	int shapesCount = 0;
	for (auto itr = m_shapesContainer->begin(); itr != m_shapesContainer->end(); ++itr)
	{
		if (sides == (*itr)->getSides())
		{
			shapesCount++;

			// Determine the suffix of the number
			// P.S. Nesting ternary operations is a bad idea
			std::cout << "Found a " << (*itr)->getType() << " shape, this is the " << shapesCount
				<< (shapesCount % 10 == 1 ? "st" : shapesCount % 10 == 2 ? "nd" : shapesCount % 10 == 3 ? "rd" : "th")
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
	std::sort(m_shapesContainer->begin(), m_shapesContainer->end(),
	          [=](const Shape* shape1, const Shape* shape2)
	          {
		          return shape1->getVolume() < shape2->getVolume();
	          }
	);

	std::for_each(m_shapesContainer->begin(), m_shapesContainer->end(), [](const Shape* shape)
	              {
		              std::cout << "Shape " << shape->getType() << " with volume: " << shape->getVolume() << std::endl;;
	              });
}

/** Prints all shapes sorted by perimeter in descending order
*
*/
void ShapeSorter::getShapesPerimeterDesc() const
{
	std::sort(m_shapesContainer->begin(), m_shapesContainer->end(),
	          [=](const Shape* shape1, const Shape* shape2)
	          {
		          return shape1->getPerimeter() < shape2->getPerimeter();
	          }
	);

	std::for_each(m_shapesContainer->begin(), m_shapesContainer->end(), [](const Shape* shape)
	              {
		              std::cout << "Shape " << shape->getType() << " with perimeter: " << shape->getPerimeter() << std::endl;
	              });
}
