// Class header
#include "shapesorter.h"

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <algorithm>

//----------------------------------------------------------------------
// Local Includes
//----------------------------------------------------------------------
#include "shape.h"



/**
 * Constructs shape.
 *
 * @param type String that represents the type of this shape
 * @param sidecount How many sides a shape of this type has
 */
ShapeSorter::ShapeSorter(const ShapeVectorSPtr& shapes)
	: m_shapes(shapes)
{
	// Empty by design
}

/**
 * Destroys shape.
 *
 * Virtual to ensure derived types are destroyed correctly when
 * deleted via base class pointer.
 */
ShapeSorter::~ShapeSorter()
{
	// Empty by design
}

/**
 * Shapes of the given type are printed to stdout.
 *
 * @param type Shapes of this type will be printed
 */
void ShapeSorter::printByTypeMatch(const std::string& type)
{
	std::cout << "Shapes of type [" << type << "]:" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	for (const auto& shape : *m_shapes)
	{
		if (shape->getType() == type)
			printShape(shape);
	}

	std::cout << std::endl << std::endl;
}

/**
 * Shapes that have the given number of sides are printed to stdout.
 *
 * @param sidecount Shapes with this number of sides will be printed
 */
void ShapeSorter::printBySideCount(int sidecount)
{
	std::cout << "Shapes with [" << sidecount << "] sides:" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	for (const auto& shape : *m_shapes)
	{
		if (shape->getSideCount() == sidecount)
			printShape(shape);
	}
	
	std::cout << std::endl << std::endl;
}

/**
 * Sorts Shapes in descending order of their Area, then prints them to stdout.
 */
void ShapeSorter::printByArea()
{
	// Sort shape vector by Area, descending
	std::sort(m_shapes->begin(), m_shapes->end(), 
		[](const ShapeUPtr& left, const ShapeUPtr& right) {
			return left->calcArea() > right->calcArea();
		}
	);

	// Print out all shapes now that they are sorted
	std::cout << "Shapes sorted by Area:" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	for (const auto& shape : *m_shapes)
	{
		printShape(shape);
	}

	std::cout << std::endl << std::endl;
}

/**
 * Sorts Shapes in descending order of their Perimeter, then prints them to stdout.
 */
void ShapeSorter::printByPerimeter()
{
	// Sort shape vector by Perimeter, descending
	std::sort(m_shapes->begin(), m_shapes->end(), 
		[](const ShapeUPtr& left, const ShapeUPtr& right) {
			return left->calcPerimeter() > right->calcPerimeter();
		}
	);

	// Print out all shapes now that they are sorted
	std::cout << "Shapes sorted by Perimeter:" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	for (const auto& shape : *m_shapes)
	{
		printShape(shape);
	}

	std::cout << std::endl << std::endl;
}

/**
 * Helper function to print a single Shape to stdout.
 *
 * @param shape Shape that is to be printed to stdout.
 */
void ShapeSorter::printShape(const ShapeUPtr& shape)
{
	std::string output;

	output = "Shape[" + shape->getType() + "]:";
	std::cout << std::setw(20) << std::left << output;

	output = "Sides = " + std::to_string(shape->getSideCount());
	std::cout << std::setw(12) << std::left << output;

	output = "Perim = " + std::to_string(shape->calcPerimeter());
	std::cout << std::setw(20) << std::left << output;

	output = "Area = " + std::to_string(shape->calcArea());
	std::cout << std::setw(20) << std::left << output;

	std::cout << std::endl;
}
