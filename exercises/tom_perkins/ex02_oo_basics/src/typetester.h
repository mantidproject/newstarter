#ifndef TYPETESTER_H_
#define TYPETESTER_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shapetester.h"
#include <string>
#include <algorithm>

/**
 * \brief Tests Shapes against the given type
 */
class TypeTester : public ShapeTester  
{
public:
	TypeTester(const std::string &typeIn);
	bool match(const std::shared_ptr<Shape> &toCompare) const;

private:
	std::string type;
};

#endif