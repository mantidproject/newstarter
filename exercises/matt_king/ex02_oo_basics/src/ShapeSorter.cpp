#include "ShapeSorter.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

ShapeSorter::ShapeSorter(std::vector<Shape> shapes){
	shapesToSort = shapes;
}

std::vector<Shape> ShapeSorter::getShapes() const{
	return shapesToSort;
}

int typeIsEqual(std::vector<Shape>::iterator it, std::string typeToCompare)
{
	return (it->getType()).compare(typeToCompare);
}


int ShapeSorter::printShapesThatMatchType(std::string type) const{
	int shapeNumber = 0;
	std::vector<Shape> shapes = getShapes();
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		if ((it->getType()).compare(type) == 0)
		{
			std::cout << it->getType().c_str() << shapeNumber << std::endl;
			shapeNumber++;
		}
	}
	return 0;
}

std::string identifyShapeByNumberOfSides(int noOfSides)
{
	if (noOfSides == 1) { return "Circle"; }
	if (noOfSides == 3) { return "Triangle"; }
	if (noOfSides == 4) { return "Quadrilateral"; }
	else {return 0;}
}

int ShapeSorter::printShapesThatMatchNumberOfSides(int noOfSides) const{
	std::vector<Shape> shapes = getShapes();
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		if (identifyShapeByNumberOfSides(noOfSides).compare("Circle") == 0)
		{
			std::cout << it->getType().c_str() << std::endl;
		}
		if (identifyShapeByNumberOfSides(noOfSides).compare("Triangle") == 0)
		{
			std::cout << it->getType().c_str() << std::endl;
		}
		if (identifyShapeByNumberOfSides(noOfSides).compare("Quadrilateral") == 0)
		{
			std::cout << it->getType().c_str() << std::endl;
		}
	}
	return 0;
}
int ShapeSorter::printAreasDesc() const
{
	std::vector<double> areas;
	std::vector<Shape> shapes = getShapes();
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		areas.push_back(it->getArea());
	}
	std::sort(areas.begin(), areas.end(), std::greater<double>());
	
	std::cout << "AREAS IN DESCENDING ORDER: \n";

	for (int i = 0; i != areas.size(); i++)
	{
		std::cout << areas[i] << std::endl;
	}
	return 0;
}
int ShapeSorter::printPerimeterDesc() const
{
	std::vector<double> perimeters;
	std::vector<Shape> shapes = getShapes();
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		perimeters.push_back(it->getPerimeter());
	}
	std::sort(perimeters.begin(), perimeters.end(), std::greater<double>());
	std::cout << "PERIMETERS IN DESCENDING ORDER: \n";
	for (int i = 0; i != perimeters.size(); i++)
	{
		std::cout << perimeters[i] << std::endl;
	}
	return 0;
}
