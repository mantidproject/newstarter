#ifndef EX2_SHAPE_SORTER
#define EX2_SHAPE_SORTER
#include "Shape.h"
#include <algorithm>
#include <memory>
#include <ostream>
#include <vector>

class ShapeSorter {
public:
  using UniqueShapePtr = std::unique_ptr<Shape>;
  using ShapeVector = std::vector<UniqueShapePtr>;
  ShapeSorter(ShapeVector Shapes, std::ostream &OutputStream);
  void printOfType(ShapeType Type);
  void printWithSides(int N);
  void printByAreaDescending();
  void printByPerimeterDescending();

private:
  void printShape(Shape const &Shape);
  template <typename ShapePredicate>
  void printWhere(ShapePredicate ShouldPrint);
  template <typename ComparisonFunction>
  void printOrderedBy(ComparisonFunction Compare);
  void printAll();
  ShapeVector m_Shapes;
  std::ostream &m_OutputStream;
};

/** Prints all shapes s for which ShapePredicate(s) returns an object which is
 * contextually convertible to true.
 * @param ShouldPrint Predicate which defines the set of shapes to print.
 */
template <typename ShapePredicate>
void ShapeSorter::printWhere(ShapePredicate ShouldPrint) {
  std::for_each(m_Shapes.cbegin(), m_Shapes.cend(),
                [this, &ShouldPrint](UniqueShapePtr const &Shape) -> void {
                  if (ShouldPrint(*Shape)) {
                    printShape(*Shape);
                  }
                });
  m_OutputStream << std::endl;
}

/** Prints all the shapes in the order determined by the comparison function
 * Compare.
 * @param Compare A fuction accepting two shapes which returns true if they are
 * ordered correctly, false if they are not.
 */
template <typename ComparisonFunction>
void ShapeSorter::printOrderedBy(ComparisonFunction Compare) {
  std::sort(m_Shapes.begin(), m_Shapes.end(),
            [&Compare](UniqueShapePtr const &First, UniqueShapePtr const &Last)
                -> bool { return Compare(*First, *Last); });
  printAll();
}
#endif // EX2_SHAPE_SORTER
