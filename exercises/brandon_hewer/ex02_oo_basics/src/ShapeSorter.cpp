//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "ShapeSorter.h"

/*
 * Constructs a new ShapeSorter for the specified vector of shapes.
 *
 * @param shapes	A vector containing pointers to shape objects.
 */
ShapeSorter::ShapeSorter(const std::vector<Shape*>& shapes) {
	m_shapes = shapes;
}

/*
 * Destructor for this ShapeSorter.
 */
ShapeSorter::~ShapeSorter() {
}

/*
 * Sorts the vector of shapes by area, in the specified sort direction.
 *
 * @param direction	The direction in which to sort:
 *                  ShapeSorter::ASCENDING (true) - Sort by increasing area.
 *                  ShapeSorter::DESCENDING (false) - Sort by decreasing area.
 */
ShapeSorter ShapeSorter::sortByArea(bool direction) const {
	// Copy vector of shapes.
	std::vector<Shape*> n_shapes(m_shapes);
	bool(*sorter) (Shape*, Shape*);

	// Check whether the specified direction is ascending or
	// descending.
	if (direction == ASCENDING) {

		// Create a sorter function for ascending sorting
		// by area.
		sorter = [](Shape* s1, Shape* s2) -> bool {
			return s1->area() < s2->area();
		};
	}
	else {

		// Create a sorter function for descending sorting
		// by area.
		sorter = [](Shape* s1, Shape* s2) -> bool {
			return s1->area() > s2->area();
		};
	}

	// Sort and return new ShapeSorter for sorted vector
	// of shapes.
	sort(n_shapes.begin(), n_shapes.end(), sorter);
	return ShapeSorter(n_shapes);
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
	// Copy vector of shapes.
	std::vector<Shape*> n_shapes(m_shapes);
	bool(*sorter) (Shape*, Shape*);

	// Check whether the specified direction is ascending or
	// descending.
	if (direction == ASCENDING) {

		// Create a sorter function for ascending sorting
		// by perimeter.
		sorter = [](Shape* s1, Shape* s2) -> bool {
			return s1->perimeter() < s2->perimeter();
		};
	}
	else {

		// Create a sorter function for descending sorting
		// by perimeter.
		sorter = [](Shape* s1, Shape* s2) -> bool {
			return s1->perimeter() > s2->perimeter();
		};
	}

	// Sort and return new ShapeSorter for sorted vector
	// of shapes.
	sort(n_shapes.begin(), n_shapes.end(), sorter);
	return ShapeSorter(n_shapes);
}

/*
 * Filters the vector of shapes by their type (name).
 *
 * @param type	The type to filter by.
 *
 * @return		A ShapeSorter for the filtered vector of shapes.
 */
ShapeSorter ShapeSorter::filterByType(std::string type) const {

	// Create type filter function.
	auto filter = [&type](const Shape* s) -> bool {
		return s->name() == type;
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
ShapeSorter ShapeSorter::filterBy(std::function<bool (const Shape*)> filter) const {
	std::vector<Shape*> filtered;

	// Iterate through all shapes in this ShapeSorter's vector of
	// shapes.
	for (auto i = m_shapes.begin(); i != m_shapes.end(); ++i) {

		// Check whether the current shape passes the filter.
		if (filter(*i)) {
			filtered.push_back(*i);
		}
	}

	return ShapeSorter(filtered);
}

/*
 * @return	The string representation of this ShapeSorter.
 */
std::string ShapeSorter::toString() const {
	std::ostringstream ss;
	
	// Iterate through all shapes in this ShapeSorter's vector of
	// shapes.
	for (auto i = m_shapes.begin(); i != m_shapes.end(); ++i) {
		ss << (*i)->toString() << "\n";
	}

	return ss.str();
}

/*
 * Appends the specified ShapeSorter's string representation to the
 * specified output stream.
 *
 * @param os		The output stream to append to.
 *
 * @param sorter	The ShapeSorter whose string representation to
 *					append.
 *
 * @return			The output stream with the string representation
 *					of the specificed ShapeSorter appended.
 */
std::ostream &operator<<(std::ostream &os, const ShapeSorter& sorter) {
	return os << sorter.toString();
}