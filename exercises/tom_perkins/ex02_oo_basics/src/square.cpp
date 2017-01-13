#include "square.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Construct a new Square with given side
 * \param sideIn Length of side of square
 * \param nameIn Name to give the shape
 */
Square::Square(double sideIn, std::string nameIn)
    : Rectangle(sideIn, sideIn, nameIn, "square") {}
