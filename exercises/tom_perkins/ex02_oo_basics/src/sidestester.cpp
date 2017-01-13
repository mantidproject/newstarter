#include "sidestester.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Initialises a SidesTester with the number of sides to compare to
 * \param numSidesIn Number of sides to compare to
 */
SidesTester::SidesTester(const int numSidesIn) : numSides(numSidesIn){};

/**
 * \brief Tests if the given shape matches the chosen number of sides
 * \param toCompare Reference to the Shape to compare to
 * \returns True for a match of numbers of sides, else false
 */
bool SidesTester::match(const Shape &toCompare) const {
  return numSides == toCompare.sides;
}