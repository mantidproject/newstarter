#ifndef SHAPESORTER_H
#define SHAPESORTER_H


#include <functional>
#include <vector>
#include <iostream>
#include "shape.h"


class ShapeSorter{

  
private:
  std::vector<Shape*> m_shapes;
  void printOnCondition (const std::function<bool (Shape *shape)> pred) const;
  void printInOrder(const std::function<bool (Shape *s1, Shape *s2)> compare) const;

  
public:
  ShapeSorter(std::vector<Shape*> shapes);
  void setShapes(const std::vector<Shape*> shapes);
  void shapesOfType(const ShapeType type) const;
  void shapesOfNSides(const int num) const;
  void shapesInAreaOrder() const;
  void shapesInPerimeterOrder() const;

  
};


#endif
