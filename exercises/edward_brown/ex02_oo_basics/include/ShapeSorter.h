#ifndef EX2_SHAPE_SORTER
#define EX2_SHAPE_SORTER
#include "Shape.h"

class ShapeSorter {
  public:
    ShapeSorter(std::vector<std::unique_ptr<Shape>> Shapes);
    void printOfType(std::string Type) const;
    void printWithSides(int N) const;
    void printVolumeDescending() const;
    void printPerimeterdDescending() const;
  private:
    template <typename ShapePredicate>
    void printWhere(ShapePredicate ShouldPrint) const {
      for(auto&& Shape : m_Shapes) {
        if(ShouldPrint(Shape)) {
          std::cout << Shape << '\n';
        }
        std::cout << std::endl;
      }
    }

    template <typename ComparisonFunction>
    void printOrderedBy(ComparisonFunction Compare) const {

    }

    std::vector<std::unique_ptr<Shape>> m_Shapes;
};


#endif // EX2_SHAPE_SORTER
