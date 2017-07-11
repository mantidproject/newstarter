//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "ShapeSorter.h"

/*
 * Constructs a new ShapeSorter for the specified vector of shapes.
 *
 * @param shapes	A vector containing pointers to shape objects.
 */
ShapeSorter::ShapeSorter(const std::vector<const Shape*>& shapes) {
	m_shapes = shapes;
}

/*
 * Sorts the vector of shapes by area, in the specified sort direction.
 *
 * @param direction	The direction in which to sort:
 *                  ShapeSorter::ASCENDING (true) - Sort by increasing area.
 *                  ShapeSorter::DESCENDING (false) - Sort by decreasing area.
 */
ShapeSorter ShapeSorter::sortByArea(bool direction) const {
	std::function<double(const Shape*)> valueFunc;
	valueFunc = [](const Shape* shape) -> double {
		return shape->area();
	};

	return sortBy(valueFunc, direction);
}

/*
 * Sorts the vector of shapes by perimeter, in the specified sort direction.
 * 
 * @param direction	The direction in which to sort:
 *					ShapeSorter::ASCENDING (true) - Sort by increasing perimeter.
 *					ShapeSorter::DESCENDING (false) - Sort b
 *
 * @return			A ShapeSorter for the sorted vector of shapes.
 */
ShapeSorter ShapeSorter::sortByPerimeter(bool direction) const {
	std::function<double(const Shape*)> valueFunc;
	valueFunc = [](const Shape* shape) -> double {
		return shape->perimeter();
	};

	return sortBy(valueFunc, direction);
}

/*
 * Filters the vector of shapes by their type (name).
 *
 * @param type	The type to filter by.
 *
 * @return		A ShapeSorter for the filtered vector of shapes.
 */
ShapeSorter ShapeSorter::filterByType(ShapeType type) const {

	// Create type filter function.
	auto filter = [&type](const Shape* s) -> bool {
		return s->type() == type;
	};
	return filterBy(filter);
}

/*
 * Filters the vector of shapes by their number of sides.
 *
 * @param numSides	The number of sides to filter by.
 *
 * @return			A ShapeSorter for the filtered vector of
 *					shapes.
 */
ShapeSorter ShapeSorter::filterBySideNumber(int numSides) const {

	// Create number of sides filter function.
	auto filter = [numSides](const Shape* s) -> bool {
		return s->numberOfSides() == numSides;
	};
	return filterBy(filter);
}

/*
 * Filters the vector of shapes by a filter function.
 *
 * The filter function must take a pointer to a Shape object
 * and return a boolean - where true represents passing the
 * filter and false represents not passing.
 *
 * @param filter	The filter function.
 *
 * @return			A ShapeSorter for the filtered vector of
 *					shapes.
 */
ShapeSorter ShapeSorter::filterBy(const std::function<bool (const Shape*)> filter) const {
	std::vector<const Shape*> filtered;

	// Iterate through all shapes in this ShapeSorter's vector of
	// shapes.
	for (const auto& shape : m_shapes) {

		// Check whether the current shape passes the filter.
		if (filter(shape)) {
			filtered.push_back(shape);
		}
	}

	return ShapeSorter(filtered);
}

template<typename T>
ShapeSorter ShapeSorter::sortBy(const std::function<T (const Shape*)> valueOf, 
	bool direction) const {
	// Copy vector of shapes.
	std::vector<const Shape*> n_shapes(m_shapes);
	std::function<bool (const Shape*, const Shape*)> sorter;
	
	// Check whether the specified direction is ascending or
	// descending.
	if (direction == ASCENDING) {

		// Create a sorter function for ascending sorting.
		sorter = [&](const Shape* s1, const Shape* s2) -> bool {
			return valueOf(s1) < valueOf(s2);
		};
	}
	else if (direction == DESCENDING) {
		
		// Create a sorter function for descending sorting.
		sorter = [&](const Shape* s1, const Shape* s2) -> bool {
			return valueOf(s1) > valueOf(s2);
		};
	}

	// Sort and return new ShapeSorter for sorted vector
	// of shapes.
	sort(n_shapes.begin(), n_shapes.end(), sorter);
	return ShapeSorter(n_shapes);
}

/*
 * @return	The string representation of this ShapeSorter.
 */
std::string ShapeSorter::toString() const {
	std::string str;
	
	// Iterate through all shapes in this ShapeSorter's vector of
	// shapes.
	for (const auto& shape : m_shapes) {
		str += shape->toString() + "\n";
	}

	return str;
}

/*
 * Appends the specified ShapeSorter's string representation to the
 * specified output stream.
 *
 * @param os		The output stream to append to.
 * @param sorter	The ShapeSorter whose string representation to
 *					append.
 *
 * @return			The output stream with the string representation
 *					of the specificed ShapeSorter appended.
 */
std::ostream &operator<<(std::ostream &os, const ShapeSorter& sorter) {
	return os << sorter.toString();
}