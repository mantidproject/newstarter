#include "ShapeSorter.h"

bool ShapeSorter::compare_area(Shape* &s1, Shape* &s2)
{
	return s1->find_area() > s2->find_area();
}

bool ShapeSorter::compare_perimeter(Shape* &s1, Shape* &s2)
{
	return s1->find_perimeter() > s2->find_perimeter();
}

void ShapeSorter::print_type(std::ostream &out, std::vector<Shape*> &all, std::string &type) const
{
	for (const auto &all_shapes : all)
	{
		if (all_shapes->get_type() == type)
		{
			all_shapes->print_details(out);
		}
	}
}

void ShapeSorter::print_sides(std::ostream &out, std::vector<Shape*> &all, int &sides) const
{
	for (const auto &all_shapes : all)
	{
		if (all_shapes->get_sides() == sides)
		{
			all_shapes->print_details(out);
		}
	}
}

void ShapeSorter::print_area_descending(std::ostream &out, std::vector<Shape*> &all) const
{
	std::sort(all.begin(), all.end(), compare_area);
	for (const auto &all_shapes : all)
	{
		all_shapes->print_details(out);
	}
}

void ShapeSorter::print_perimeter_descending(std::ostream &out, std::vector<Shape*> &all) const
{
	std::sort(all.begin(), all.end(), compare_perimeter);
	for (const auto &all_shapes : all)
	{
		all_shapes->print_details(out);
	}
}
