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

bool sortByArea(Shape firstShape, Shape secondShape)
{
	return (firstShape.area > secondShape.area);
}

bool sortByPerimeter(Shape firstShape, Shape secondShape)
{
	return (firstShape.perimeter > secondShape.perimeter);
}

int typeIsEqual(std::vector<Shape>::iterator it, std::string typeToCompare)
{
	return (it->getType()).compare(typeToCompare);
}


int ShapeSorter::printShapesThatMatchType(std::string type) const{
	int shapeNumber = 0;
	std::vector<Shape> shapes = getShapes();
	std::cout << "SHAPES OF TYPE " << type.c_str() << "\n";

	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		if ((it->getType()).compare(type) == 0)
		{
			std::cout << it->getType().c_str() << shapeNumber << std::endl;
			shapeNumber++;
		}	
	}
	std::cout << "\n";
	return 0;
}

int ShapeSorter::printShapesThatMatchNumberOfSides(int noOfSides) const{
	std::vector<Shape> shapes = getShapes();

	std::cout << "SHAPES WITH " << noOfSides << " SIDE(s): " << std::endl;
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		if (it->noOfSides == noOfSides)
		{
			it->print();
		}
	}
	std::cout << "\n";
	return 0;
}
int ShapeSorter::printAreasDesc() const
{
	std::vector<Shape> shapes = getShapes();
	
	std::sort(shapes.begin(), shapes.end(), sortByArea);

	std::cout << "AREAS IN DESCENDING ORDER: \n";

	for (int i = 0; i != shapes.size(); i++)
	{
		shapes[i].print();
	}
	std::cout << "\n";
	return 0;
}
int ShapeSorter::printPerimeterDesc() const
{
	std::vector<Shape> shapes = getShapes();
	
	std::sort(shapes.begin(), shapes.end(), sortByPerimeter);
	std::cout << "PERIMETERS IN DESCENDING ORDER: \n";
	for (int i = 0; i != shapes.size(); i++)
	{
		shapes[i].print();
	}
	std::cout << "\n";
	return 0;
}
