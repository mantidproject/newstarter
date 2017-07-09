#ifndef EX2_SHAPE_SORTER
#define EX2_SHAPE_SORTER
#include <algorithm>
#include <memory>
#include <ostream>
#include <vector>
#include "Shape.h"

class ShapeSorter {
   public:
    using UniqueShape = std::unique_ptr<Shape>;
    using ShapeVector = std::vector<UniqueShape>;
    ShapeSorter(ShapeVector Shapes, std::ostream& OutputStream);
    void printOfType(std::string Type);
    void printWithSides(int N);
    void printByAreaDescending();
    void printByPerimeterDescending();

   private:
    void printShape(Shape const* const Shape);
    template <typename ShapePredicate>
    void printWhere(ShapePredicate ShouldPrint);
    template <typename ComparisonFunction>
    void printOrderedBy(ComparisonFunction Compare);
    void printAll();
    ShapeVector m_Shapes;
    std::ostream& m_OutputStream;
};

template <typename ShapePredicate>
void ShapeSorter::printWhere(ShapePredicate ShouldPrint) {
    std::for_each(m_Shapes.cbegin(), m_Shapes.cend(),
                  [this, &ShouldPrint](UniqueShape const& Shape) -> void {
                    if(ShouldPrint(*Shape)) {
                      printShape(Shape.get());
                    }
                  });
    m_OutputStream << std::endl;
}

template <typename ComparisonFunction>
void ShapeSorter::printOrderedBy(ComparisonFunction Compare) {
    std::sort(m_Shapes.begin(), m_Shapes.end(),
              [&Compare](UniqueShape const& First,
                         UniqueShape const& Last) -> bool {
                  return Compare(*First, *Last);
              });
    printAll();
}
#endif  // EX2_SHAPE_SORTER
