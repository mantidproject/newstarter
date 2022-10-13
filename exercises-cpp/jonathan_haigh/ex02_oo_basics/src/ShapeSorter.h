#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

class ShapeSorter {
public:
	ShapeSorter() {};
	virtual ~ShapeSorter() {};

	void add(std::shared_ptr<Shape>);

	void matchName(const std::string& name) const;
	void matchSides(const int n) const;
	void descendingArea() const;
	void descendingPerimeter() const;

private:
	std::vector<std::shared_ptr<Shape>> m_shape_list;
};
