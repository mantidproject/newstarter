#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"
#include "typetester.h"
#include "sidestester.h"
#include <vector>
#include <memory>
#include <iosfwd>
#include <string>
#include <algorithm>

/**
 * \brief Selects shapes from a vector according
 * to type, number of sides, and/or sorts them
 *
 * ShapeSorter's methods work on a vector of 
 * shared_ptr's to Shapes. It works as a filter,
 * selecting by type/number of sides, or sorting
 * in order of volume/perimeter.
 *
 */
class ShapeSorter 
{
public:
	std::vector<std::shared_ptr<Shape> > selectByType(const std::vector<std::shared_ptr<Shape> > &shapes, const std::string &type) const;
	std::vector<std::shared_ptr<Shape> > selectBySides(const std::vector<std::shared_ptr<Shape> > &shapes, const int numSides) const;
	std::vector<std::shared_ptr<Shape> > sortByArea(const std::vector<std::shared_ptr<Shape> > &shapes) const;
	std::vector<std::shared_ptr<Shape> > sortByPerimeter(const std::vector<std::shared_ptr<Shape> > &shapes) const;

private:
	std::vector<std::shared_ptr<Shape> > select(const std::vector<std::shared_ptr<Shape> > &shapes, const ShapeTester &tester) const;
	std::vector<std::shared_ptr<Shape> > sort(const std::vector<std::shared_ptr<Shape> > &shapes, bool predicate(const std::shared_ptr<Shape> &x, const std::shared_ptr<Shape> &y)) const;
};

#endif