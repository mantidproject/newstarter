#pragma once

#include "Shape.h"
#include <memory>
#include <functional>

class ShapeSorter
{
public:
  using Shape_cuptr = std::unique_ptr<const Shape>;
	static bool AreaComparator(const Shape_cuptr &s1, const Shape_cuptr &s2);
	static bool PerimeterComparator(const Shape_cuptr &s1, const Shape_cuptr &s2);
	void PrintBasedOnType(const std::vector<Shape_cuptr> &shapes, std::string type) const;
	void PrintBasedOnNSides(const std::vector<Shape_cuptr> &shapes, int numSides) const;
	std::vector<Shape_cuptr> SortByAreaDesc(const std::vector<Shape_cuptr> &shapes) const;
	std::vector<Shape_cuptr> SortByPerimeterDesc(const std::vector<Shape_cuptr> &shapes) const;
	void PrintShapes(const std::vector<Shape_cuptr> &shapes) const;

};
