#include "ShapeSorter.h"
#include <cassert>
#include <ostream>

/** Makes shape sorter with the specified collection of shapes and output stream
 * to print to.
 * @param Shapes The collection of shapes to sort and filter.
 * @param OutputStream The output stream to print to when requested.
 */
ShapeSorter::ShapeSorter(ShapeVector Shapes, std::ostream &OutputStream)
    : m_Shapes(std::move(Shapes)), m_OutputStream(OutputStream) {}

/** Prints Shape to this sorter's output stream
 * @param The shape to be printed.
 */
void ShapeSorter::printShape(Shape const &Shape) {
  m_OutputStream << Shape << '\n';
}

/// Prints all shapes in the shape sorter.
void ShapeSorter::printAll() {
  std::for_each(
      m_Shapes.cbegin(), m_Shapes.cend(),
      [this](UniqueShapePtr const &Shape) -> void { printShape(*Shape); });
  m_OutputStream << std::endl;
}

/** Prints all shapes with the specified name.
 * @param Name The shape name printed shapes all have.
 */
void ShapeSorter::printOfType(ShapeType Type) {
  printWhere([&Type](Shape const &PrintCandidate) -> bool {
    return PrintCandidate.getShapeType() == Type;
  });
}

/** Prints all shapes with the specified number of sides
 *  @param NumberOfSides The number of sides printed shapes all have
 */
void ShapeSorter::printWithSides(int NumberOfSides) {
  printWhere([NumberOfSides](Shape const &PrintCandidate) -> bool {
    return PrintCandidate.getSideCount() == NumberOfSides;
  });
}

/// Prints all shapes ordered by their areas from highest to lowsest.
void ShapeSorter::printByAreaDescending() {
  printOrderedBy([](Shape const &First, Shape const &Second) -> bool {
    return First.getArea() > Second.getArea();
  });
}

/** Prints all shapes held by the shape vector ordered by their perimeters
 *  ordered from highest to lowsest. **/
void ShapeSorter::printByPerimeterDescending() {
  printOrderedBy([](Shape const &First, Shape const &Second) -> bool {
    return First.getPerimeter() > Second.getPerimeter();
  });
}
