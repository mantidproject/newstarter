#ifndef SQUARE_H_
#define SQUARE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "rectangle.h"

/**
 * \brief Square represents a square, a special type of Rectangle
 * with x = y
 */
class Square : public Rectangle
{
public:
	Square(double sideIn);
};

#endif