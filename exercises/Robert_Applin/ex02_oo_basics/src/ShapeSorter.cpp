#include "ShapeSorter.h"
#include "Shape.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>

namespace {

/**
 * template to get specific shapes using a specific filter argument
 * @params vector of shape pointers, and filter lambda
 * @return vector of filtered shapes
 */
template <typename Predicate>
std::vector<Shape const *>
filterShapes(std::vector<Shape const *> const &shapes,
             Predicate const &filter) {
  std::vector<Shape const *> filteredShapes;
  std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(filteredShapes),
               filter);
  return filteredShapes;
}

/**
 * template to sort shapes in order using a specific condition
 * @params vector of shape pointers, and comparison lambda
 * @return vector of sorted shapes
 */
template <typename Comparison>
std::vector<Shape const *> sortShapes(std::vector<Shape const *> const &shapes,
                                      Comparison const &compare) {
  std::vector<Shape const *> sortedShapes(shapes);
  std::sort(sortedShapes.begin(), sortedShapes.end(), compare);
  return sortedShapes;
}

/**
 * function that prints out shape details
 * @params output stream, and a reference to a shape
 * @return output stream
 */
std::ostream &printShapeTo(std::ostream &output, Shape const &shape) {
  output << "Type: " << std::setw(9) << shape.getType() << std::setw(9)
         << "Area: " << std::setw(9) << shape.getArea() << std::setw(14)
         << "Perimeter: " << std::setw(9) << shape.getPerimeter();
  return output;
}

/**
 * function to compare the areas of two shapes
 * @params two shapes
 * @return true boolean if shape1's area > shape2's area
 */
bool compareVolume(Shape const *shape1, Shape const *shape2) {
  return shape1->getArea() > shape2->getArea();
}

/**
 * function to compare the perimeters of two shapes
 * @params two shapes
 * @return true boolean if shape1's perimeter > shape2's perimeter
 */
bool comparePerimeter(Shape const *shape1, Shape const *shape2) {
  return shape1->getPerimeter() > shape2->getPerimeter();
}

} // namespace

// Moves shapes into m_shapes, leaving shapes empty
ShapeSorter::ShapeSorter(std::vector<Shape const *> &&shapes)
    : m_shapes(std::move(shapes)) {}

// Copy shapes into m_shapes. So a copy is made
ShapeSorter::ShapeSorter(std::vector<Shape const *> const &shapes)
    : m_shapes(shapes) {}

/**
 * method to create a new ShapeSorter of the filtered shapes
 * @params string representing a type
 * @return ShapeSorter of filtered shapes
 */
ShapeSorter ShapeSorter::filterByType(std::string const &type) const {
  return ShapeSorter(filterShapes(
      m_shapes, [&](Shape const *shape) { return shape->getType() == type; }));
}

/**
 * method to create a new ShapeSorter of the filtered shapes
 * @params size_t representing the number of edges
 * @return ShapeSorter of filtered shapes
 */
ShapeSorter
ShapeSorter::filterByNumberOfEdges(std::size_t numberOfEdges) const {
  return ShapeSorter(
      filterShapes(m_shapes, [&numberOfEdges](Shape const *shape) {
        return shape->getNumberOfEdges() == numberOfEdges;
      }));
}

/**
 * method to create a new ShapeSorter of the sorted shapes by volume
 * @params none
 * @return ShapeSorter of sorted shapes
 */
ShapeSorter ShapeSorter::sortByVolume() const {
  return ShapeSorter(sortShapes(m_shapes, compareVolume));
}

/**
 * method to create a new ShapeSorter of the sorted shapes by volume
 * @params none
 * @return ShapeSorter of sorted shapes
 */
ShapeSorter ShapeSorter::sortByPerimeter() const {
  return ShapeSorter(sortShapes(m_shapes, comparePerimeter));
}

// Used by overloaded stream operator to find beginning of the shapesorter
// object
std::vector<Shape const *>::const_iterator ShapeSorter::begin() const {
  return m_shapes.begin();
}

// Used by overloaded stream operator to find end of the shapesorter object
std::vector<Shape const *>::const_iterator ShapeSorter::end() const {
  return m_shapes.end();
}

std::ostream &operator<<(std::ostream &output, ShapeSorter const &sorter) {
  for (auto const &shape : sorter)
    printShapeTo(output, *shape) << '\n';
  return output;
}
