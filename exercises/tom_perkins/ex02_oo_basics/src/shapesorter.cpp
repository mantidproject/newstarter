#include "shapesorter.h"

typedef std::vector<std::shared_ptr<Shape> > vecShape;

//----------------------------------------------------------------------
// Free functions
//----------------------------------------------------------------------

//bool compareAreas(

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

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

	for (auto iter = shapes.begin(); iter != shapes.end(); iter++)
	{
		if ((*iter)->type == typeLower)
		{
			selected.push_back(*iter);
		}
	}

	return selected;
}

///**
// * \brief Selects all shapes in the given vector that have the given number of sides
// *
// * \param shapes Vector of shared_ptr's to Shape objects, to select from
// * \param numSides Number of sides to match
// */
//void ShapeSorter::selectBySides(const std::vector<std::shared_ptr<Shape> > &shapes, const int numSides) const
//{
//	m_stream << std::endl << "Shapes with " << numSides << " sides are:" << std::endl;
//	for (auto iter = shapes.begin(); iter != shapes.end(); iter++)
//	{
//		if ((*iter)->sides == numSides)
//		{
//			m_stream << (*iter)->name << std::endl;
//		}
//	}
//}
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
