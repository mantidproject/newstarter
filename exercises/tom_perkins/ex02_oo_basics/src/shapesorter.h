#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"
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
 * It is initialised with a stream to which the 
 * output of each filtering command will be written.
 *
 */
class ShapeSorter 
{
public:
	ShapeSorter(std::ostream &stream);
	void selectByType(const std::vector<std::shared_ptr<Shape> > &shapes, const std::string &type) const;
	void selectBySides(const std::vector<std::shared_ptr<Shape> > &shapes, const int numSides) const;
	void sortByArea(const std::vector<std::shared_ptr<Shape> > &shapes) const;
	void sortByPerimeter(const std::vector<std::shared_ptr<Shape> > &shapes) const;

private:
	std::ostream &m_stream;
};

#endif