#include "ShapeSorter.h"
#include <algorithm>

ShapeSorter::ShapeSorter(std::vector<Shape *> shapes) : m_shapes(shapes){};

void ShapeSorter::setShapes(const std::vector<Shape *> shapes) {
  m_shapes = shapes;
}

/** General-purpose function for printing every shape which satisfies a given
 * condition
 *
 * @param pred A lambda for which shapes should be printed
 *
 */
void ShapeSorter::printOnCondition(
    const std::function<bool(Shape *shape)> &pred) const {
  // Iterate over shapes, print those for which pred(shape) evaluates to true
  for_each(m_shapes.begin(), m_shapes.end(), [=](Shape *shape) {
    if (pred(shape)) {
      std::cout << shape->toString() << " ";
    }
  });
  std::cout << "\n";
}

/** Print all shapes of a given type
 *
 * @param type The type of shapes which should be printed
 *
 */
void ShapeSorter::shapesOfType(const ShapeType &type) const {
  printOnCondition([&](Shape *shape) { return shape->getType() == type; });
}

/** Print all shapes with a given number of sides
 *
 * @param num The number of sides which shapes printed should have
 *
 */
void ShapeSorter::shapesOfNSides(const int &num) const {
  printOnCondition([&](Shape *shape) { return shape->getNumSides() == num; });
}

/** Print all shapes, sorted in some order
 *
 * @param compare A comparison function specifying the intended ordering
 *
 */
void ShapeSorter::printInOrder(
    const std::function<bool(Shape *s1, Shape *s2)> &compare) const {
  std::vector<Shape *> tempShapes = m_shapes;
  sort(tempShapes.begin(), tempShapes.end(), compare);
  for_each(tempShapes.begin(), tempShapes.end(),
           [](Shape *shape) { std::cout << shape->toString() << " "; });
  std::cout << "\n";
}

/** Print shapes in descending order of their area */
void ShapeSorter::shapesInAreaOrder() const {
  printInOrder(
      [](Shape *s1, Shape *s2) { return s1->getArea() > s2->getArea(); });
}

/** Print shapes in descending order of their perimeter */
void ShapeSorter::shapesInPerimeterOrder() const {
  printInOrder([](Shape *s1, Shape *s2) {
    return s1->getPerimeter() > s2->getPerimeter();
  });
}
