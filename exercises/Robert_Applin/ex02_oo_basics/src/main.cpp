/**
 * Skeleton main routine
 */
#include <iomanip>
#include <iostream>
#include <vector>

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"

int main(int, char **) {
  std::vector<Shape const *> shapes;

  Circle circle(3);
  Rectangle rectangle(2, 3);
  Square square(5);
  Square square2(4);
  Triangle triangle(5, 4);
  Triangle triangle2(3, 10);

  shapes.emplace_back(&circle);
  shapes.emplace_back(&rectangle);
  shapes.emplace_back(&square);
  shapes.emplace_back(&square2);
  shapes.emplace_back(&triangle);
  shapes.emplace_back(&triangle2);

  ShapeSorter sorter(shapes);

  std::cout
      << "Here are all the shapes:\n"
      << sorter << "\nHere are the shapes sorted in order of descending area:\n"
      << sorter.sortByVolume()
      << "\nHere are the shapes sorted in order of descending perimeter:\n"
      << sorter.sortByPerimeter() << '\n';

  std::string filterType;
  std::cout << "Provide a shape type to filter by:\n";
  std::cin >> filterType;
  std::cout << "\nHere are the shapes with type " << filterType << ":\n"
            << sorter.filterByType(filterType);

  std::size_t filterNumberOfSides;
  std::cout << "\nProvide the number of sides to filter by:\n";
  std::cin >> filterNumberOfSides;
  std::cout << "\nHere are the shapes with " << filterNumberOfSides
            << " edges:\n"
            << sorter.filterByNumberOfEdges(filterNumberOfSides);

  std::cout << std::endl;
}
