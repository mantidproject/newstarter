#ifndef EX2_SHAPE_SORTER
#define EX2_SHAPE_SORTER
#include <algorithm>
#include <memory>
#include <ostream>
#include <vector>
#include "Shape.h"

class ShapeSorter {
   public:
    using ShapeVector = std::vector<std::unique_ptr<Shape>>;
    ShapeSorter(ShapeVector Shapes, std::ostream& OutputStream);
    void printOfType(std::string Type);
    void printWithSides(int N);
    void printByAreaDescending();
    void printByPerimeterDescending();

   private:
    template <typename ShapePredicate>
    void printWhere(ShapePredicate ShouldPrint);
    template <typename ComparisonFunction>
    void printOrderedBy(ComparisonFunction Compare);
    template <typename InputItterator>
    void printRange(InputItterator Begin, InputItterator End);
    ShapeVector m_Shapes;
    std::ostream& m_OutputStream;
};

template <typename InputItterator>
void ShapeSorter::printRange(InputItterator Begin, InputItterator End) {
    std::for_each(Begin, End,
                  [this](std::unique_ptr<Shape> const& shape) -> void {
                      m_OutputStream << *shape << '\n';
                  });
    m_OutputStream << std::endl;
}

template <typename ShapePredicate>
void ShapeSorter::printWhere(ShapePredicate ShouldPrint) {
    auto WhereTrueEnd = std::partition(
        m_Shapes.begin(), m_Shapes.end(),
        [&ShouldPrint](std::unique_ptr<Shape> const& PrintCandidate) -> bool {
            return ShouldPrint(*PrintCandidate);
        });
    printRange(m_Shapes.begin(), WhereTrueEnd);
}

template <typename ComparisonFunction>
void ShapeSorter::printOrderedBy(ComparisonFunction Compare) {
    std::sort(m_Shapes.begin(), m_Shapes.end(),
              [&Compare](std::unique_ptr<Shape> const& First,
                         std::unique_ptr<Shape> const& Last) -> bool {
                  return Compare(*First, *Last);
              });
    printRange(m_Shapes.cbegin(), m_Shapes.cend());
}
#endif  // EX2_SHAPE_SORTER
