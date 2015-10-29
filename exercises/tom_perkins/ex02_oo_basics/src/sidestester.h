#ifndef SIDESTESTER_H_
#define SIDESTESTER_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shapetester.h"
#include "shape.h"
#include <memory>

/**
 * \brief Tests Shapes against the given number of sides
 */
class SidesTester : public ShapeTester  
{
public:
	SidesTester(const int numSidesIn);
	bool match(const std::shared_ptr<Shape> &toCompare) const;

private:
	int numSides;
};

#endif