#include "ShapeSorter.h"
#include <iostream>
#include <algorithm>

void ShapeSorter::add(std::shared_ptr<Shape> shape) {
	m_shape_list.emplace_back(shape);
}

void ShapeSorter::matchName(const std::string& name) const {
	std::cout << "All the " << name << "s!" << std::endl;

	for (const auto& shape : m_shape_list) {
		if (shape->getName() == name)
			shape->print();
	}
}

void ShapeSorter::matchSides(const int n) const {
	std::cout << "All the " << n << " sided shapes!" << std::endl;

	for (const auto& shape : m_shape_list) {
		if (shape->getSides() == n)
			shape->print();
	}
}

void ShapeSorter::descendingArea() const {
	auto sorted_shape_list = m_shape_list;
	std::sort(sorted_shape_list.begin(), sorted_shape_list.end(),
		[](const std::shared_ptr<Shape>& shapeA, const std::shared_ptr<Shape>& shapeB) {
			return shapeA->getArea() > shapeB->getArea();
		});

	std::cout << "Shapes by area!" << std::endl;
	for (const auto& shape : sorted_shape_list)
		shape->print();
}

void ShapeSorter::descendingPerimeter() const {
	auto sorted_shape_list = m_shape_list;
	std::sort(sorted_shape_list.begin(), sorted_shape_list.end(),
		[](const std::shared_ptr<Shape>& shapeA, const std::shared_ptr<Shape>& shapeB) {
			return shapeA->getPerimeter() > shapeB->getPerimeter();
		});

	std::cout << "Shapes by perimeter!" << std::endl;
	for (const auto& shape : sorted_shape_list)
		shape->print();
}
