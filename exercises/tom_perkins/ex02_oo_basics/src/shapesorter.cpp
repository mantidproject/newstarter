#include "shapesorter.h"

typedef std::vector<std::shared_ptr<Shape> > vecShape; ///< To save typing in this implementation file

//----------------------------------------------------------------------
// Free functions
//----------------------------------------------------------------------

//bool isOfType

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Selects all shapes in the given vector that satisfy the given predicate
 *
 * \param shapes Vector of shared_ptr's to Shape objects, to select from
 * \param predicate Pointer to a function returning a bool, that determines if the given 
 * shape should be selected or not
 */
vecShape ShapeSorter::select(const vecShape &shapes, const ShapeTester &tester) const
{
	vecShape selected;
	
	for (auto iter = shapes.begin(); iter != shapes.end(); iter++)
	{
		if (tester.match(*iter))
		{
			selected.push_back(*iter);
		}
	}

	return selected;
}

/**
 * \brief Selects all shapes in the given vector that have the given type
 *
 * \param shapes Vector of shared_ptr's to Shape objects, to select from
 * \param type Shape type to match
 * \returns Vector of shared_ptr's to matching Shapes
 */
vecShape ShapeSorter::selectByType(const vecShape &shapes, const std::string &type) const
{
	vecShape selected;

	// Convert supplied type to lower-case to match the built-in type strings
	std::string typeLower(type);
	std::transform(type.begin(), type.end(), typeLower.begin(), tolower);

	TypeTester isOfType(typeLower);
	return select(shapes, isOfType);
}

/**
 * \brief Selects all shapes in the given vector that have the given number of sides
 *
 * \param shapes Vector of shared_ptr's to Shape objects, to select from
 * \param numSides Number of sides to match
 * \returns Vector of shared_ptr's to matching Shapes
 */
vecShape ShapeSorter::selectBySides(const vecShape &shapes, const int numSides) const
{
	SidesTester hasNumberOfSides(numSides);
	return select(shapes, hasNumberOfSides);
}
//
///**
// * \brief Sorts the given shapes by area, descending.
// * 
// * \param shapes Vector of shared_ptr's to Shape objects, to sort
// */
//void ShapeSorter::sortByArea(const std::vector<std::shared_ptr<Shape> > &shapes) const
//{
//	m_stream << std::endl << "Shapes sorted by area:" << std::endl;
//}
