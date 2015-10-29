#include "shapesorter.h"

typedef std::vector<std::shared_ptr<Shape> > vecShape; ///< To save typing in this implementation file

//----------------------------------------------------------------------
// Free functions
//----------------------------------------------------------------------

namespace
{
	/**
	 * \brief Compares two Shapes by area, for sorting
	 */
	bool compareAreas(const std::shared_ptr<Shape> &x, const std::shared_ptr<Shape> &y) 
	{
		return x->area() < y->area();
	}

	/**
	 * \brief Compares two Shapes by perimeter, for sorting
	 */
	bool comparePerimeters(const std::shared_ptr<Shape> &x, const std::shared_ptr<Shape> &y) 
	{
		return x->perimeter() < y->perimeter();
	}
}

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Selects all shapes in the given vector that satisfy the given predicate
 *
 * \param shapes Vector of shared_ptr's to Shape objects, to select from
 * \param tester ShapeTester that determines if the given shape should be selected or not
 * \returns Vector of selected shapes
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
 * \brief Sorts the shapes in the given vector according to the given comparator, 
 * returning a new sorted vector and leaving the original untouched
 * 
 * \param shapes Vector of shared_ptr's to Shape objects, to select from
 * \param predicate Pointer to function that determines sort order
 * \returns Vector of sorted shapes
 */
vecShape ShapeSorter::sort(const vecShape &shapes, bool predicate(const std::shared_ptr<Shape> &x, const std::shared_ptr<Shape> &y)) const
{
	vecShape sorted(shapes);
	std::sort(sorted.begin(), sorted.end(), predicate);
	return sorted;
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

/**
 * \brief Sorts the given shapes by area, descending.
 * 
 * \param shapes Vector of shared_ptr's to Shape objects, to sort
 */
vecShape ShapeSorter::sortByArea(const vecShape &shapes) const
{
	return sort(shapes, compareAreas);
}

/**
 * \brief Sorts the given shapes by perimeter, descending.
 * 
 * \param shapes Vector of shared_ptr's to Shape objects, to sort
 */
vecShape ShapeSorter::sortByPerimeter(const vecShape &shapes) const
{
	return sort(shapes, comparePerimeters);
}


