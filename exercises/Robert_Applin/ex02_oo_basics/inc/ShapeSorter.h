#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include <ostream>
#include <vector>

// Forward declare Shape
class Shape;

class ShapeSorter {
public:
  ShapeSorter(std::vector<Shape const *> &&shapes);
  ShapeSorter(std::vector<Shape const *> const &shapes);

  ShapeSorter filterByType(std::string const &type) const;
  ShapeSorter filterByNumberOfEdges(std::size_t numberOfEdges) const;
  ShapeSorter sortByVolume() const;
  ShapeSorter sortByPerimeter() const;

  std::vector<Shape const *>::const_iterator begin() const;
  std::vector<Shape const *>::const_iterator end() const;

private:
  std::vector<Shape const *> const m_shapes;
};

std::ostream &operator<<(std::ostream &output, ShapeSorter const &sorter);

#endif
