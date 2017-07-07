#include "ShapeSorter.h"

ShapeSorter::ShapeSorter(std::vector<std::unique_ptr<Shape>> Shapes,
                         std::ostream& OutputStream)
    : m_Shapes(std::move(Shapes)), m_OutputStream(OutputStream) {}

void ShapeSorter::printOfType(std::string Type) {
    printWhere([&Type](Shape const& PrintCandidate) -> bool {
        return PrintCandidate.getShapeName() == Type;
    });
}

void ShapeSorter::printWithSides(int NumberOfSides) {
    printWhere([NumberOfSides](Shape const& PrintCandidate) -> bool {
        return PrintCandidate.getSideCount() == NumberOfSides;
    });
}

void ShapeSorter::printByAreaDescending() {
    printOrderedBy([](Shape const& First, Shape const& Second) -> bool {
        return First.getArea() > Second.getArea();
    });
}

void ShapeSorter::printByPerimeterDescending() {
    printOrderedBy([](Shape const& First, Shape const& Second) -> bool {
        return First.getPerimeter() > Second.getPerimeter();
    });
}
