#include "square.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Construct a new Rectangle with given sides x, y
 * \param xIn Length of one side of rectangle
 * \param yIn Length of other side of rectangle
 */
Square::Square(double sideIn) : Rectangle(sideIn, sideIn, "Square") { }
