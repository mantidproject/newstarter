/**
 * Skeleton main routine
 */
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"

std::string toLower(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), std::tolower);
	return str;
}

std::size_t getUnsignedFrom(std::istream &input) {
  double value;
  input >> value;

  if (!input || value <= 0 || value - std::floor(value) != 0) {
    input.clear();
    throw std::runtime_error(
        "Invalid input supplied: not a whole number >= 0.");
  }
  return static_cast<std::size_t>(value);
}

std::string getLowerStringFrom(std::istream &input) {
  std::string value;
  input >> value;
  return toLower(value);
}

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
  filterType = getLowerStringFrom(std::cin);
  std::cout << "\nHere are the shapes with type " << filterType << ":\n"
            << sorter.filterByType(filterType);

  std::size_t filterNumberOfSides;
  std::cout << "\nProvide the number of sides to filter by:\n";

  try {
    filterNumberOfSides = getUnsignedFrom(std::cin);
    std::cout << "\nHere are the shapes with " << filterNumberOfSides
              << " edges:\n"
              << sorter.filterByNumberOfEdges(filterNumberOfSides);
  } catch (const std::runtime_error &exc) {
    std::cout << exc.what();
  }

  std::cout << std::endl;
}
