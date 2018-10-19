#pragma once

#include "Shape.h"
#include <memory>
#include <functional>

class ShapeSorter
{
public:
	static bool AreaComparator(const std::unique_ptr<const Shape> &s1, const std::unique_ptr<const Shape> &s2);
	static bool PerimeterComparator(const std::unique_ptr<const Shape> &s1, const std::unique_ptr<const Shape> &s2);
	void PrintBasedOnType(const std::vector<std::unique_ptr<const Shape>> &shapes, std::string type) const;
	void PrintBasedOnNSides(const std::vector<std::unique_ptr<const Shape>> &shapes, int numSides) const;
	std::vector<std::unique_ptr<const Shape>> SortByAreaDesc(const std::vector<std::unique_ptr<const Shape>> &shapes) const;
	std::vector<std::unique_ptr<const Shape>> SortByPerimeterDesc(const std::vector<std::unique_ptr<const Shape>> &shapes) const;
	void PrintShapes(const std::vector<std::unique_ptr<const Shape>> &shapes) const;

};
