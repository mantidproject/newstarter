#ifndef SHAPE_SORTER_H
#define SHAPE_SORTER_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Shape.h"

#include <algorithm>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

//===-- ShapeSorter.h - ShapeSorter definition -------*- C++ -*-==============//
//
//                          2-Dimmensional Shapes
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ShapeSorter class, which is used
/// to filter and sort vectors of shapes.
///
//===----------------------------------------------------------------------===//
class ShapeSorter
{
public:
	/// Static constant for ascending sorting.
	static const bool ASCENDING = true;
	/// Static constant for descending sorting.
	static const bool DESCENDING = false;

	/// Constructs a ShapeSorter for the specified
	/// vector of shapes.
	ShapeSorter(const std::vector<const Shape*>& shapes);

	/// Filters the vector of shapes by their type.
	/// The type of a shape is their name. Returns
	/// a shape sorter for the filtered vector.
	ShapeSorter filterByType(ShapeType type) const;

	/// Filters the vector of shapes by their number
	/// of sides. Returns a shape sorter for the
	/// filtered vector.
	ShapeSorter filterBySideNumber(int numSides) const;

	/// Sorts the vector of shapes by their area,
	/// where sort direction is specified.
	ShapeSorter sortByArea(bool direction) const;

	/// Sorts the vector of shapes by their perimeter,
	/// where sort direction is specified.
	ShapeSorter sortByPerimeter(bool direction) const;

	/// Returns the string representation of this
	/// ShapeSorter.
	std::string toString() const;
private:
	/// The vector of shapes for the ShapeSorter.
	std::vector<const Shape*> m_shapes;

	/// Filters the vector of shapes by a specified filter
	/// function. Returns a shape sorter for the filtered
	/// vector.
	ShapeSorter filterBy(const std::function<bool (const Shape*)>) const;

	template<typename T>
	ShapeSorter sortBy(const std::function<T (const Shape*)> valueFunc, 
		bool direction) const;
};

/// Adds the string representation of a specified ShapeSorter
/// to a specified output stream.
std::ostream &operator<<(std::ostream &os, const ShapeSorter&);

#endif /* SHAPE_SORTER_H */