#ifndef SHAPETESTER_H_
#define SHAPETESTER_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"
#include <memory>

/**
 * \brief Abstract base class for testing Shape objects
 */
class ShapeTester  
{
public:
	virtual bool match(const std::shared_ptr<Shape> &toCompare) const = 0;
};

#endif