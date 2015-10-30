#include "typetester.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Initialises a TypeTester with the type to compare to
 *
 * Converts to lower-case for case-insensitive comparisons.
 *
 * \param typeIn Type of shape to compare to
 */
TypeTester::TypeTester(const std::string &typeIn)
{
	type = std::string(typeIn);
	std::transform(type.begin(), type.end(), type.begin(), tolower);
}

/**
 * \brief Tests if the given shape matches the chosen type
 * \param toCompare Reference to the Shape to compare to
 * \returns True for a match of types, else false
 */
bool TypeTester::match(const Shape &toCompare) const 
{ 
	return type == toCompare.type; 
}
