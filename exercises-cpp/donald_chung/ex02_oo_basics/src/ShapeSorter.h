#ifndef SHAPE_SORTER_H
#define SHAPE_SORTER_H

#include "shape.h"
#include <vector>
#include <string>

class ShapeSorter
{
public:
	ShapeSorter();
	//dereference as vector is a pointer 
	static void print_byarea_dec(std::vector<Shape*> shapes);

	static void print_byperimeter_dec(std::vector<Shape*> shapes);

	static void print_type(std::vector<Shape*> shapes, std::string type);
	static void print_sides(std::vector<Shape*> shapes, int side);
};
#endif