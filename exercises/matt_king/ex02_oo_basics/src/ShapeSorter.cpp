#include "ShapeSorter.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

ShapeSorter::ShapeSorter(const std::vector<Shape>& shapes){
	shapesToSort = shapes;
}

std::vector<Shape> ShapeSorter::getShapes() const{
	return shapesToSort;
}

bool sortByArea(const Shape& firstShape, const Shape& secondShape)
{
	return (firstShape.area > secondShape.area);
}

bool sortByPerimeter(const Shape& firstShape, const Shape& secondShape)
{
	return (firstShape.perimeter > secondShape.perimeter);
}

int ShapeSorter::printShapesThatMatchType(const std::string& type) const{
	//prints the shapes that match the desired type given as param
	int shapeNumber = 0; //id given to shape to tell them apart. i.e circle0, circle1 etc..
	std::vector<Shape> shapes = getShapes();

	std::cout << "SHAPES OF TYPE " << type.c_str() << "\n";

	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		//see if shape type matches type given as param
		if ((it->getType()).compare(type) == 0)
		{
			std::cout << it->getType().c_str() << shapeNumber << ":" << std::endl;
			it->print();
			shapeNumber++; //increase id number
		}	
	}
	std::cout << "\n";
	return 0;
} // printShapesThatMatchTypes

int ShapeSorter::printShapesThatMatchNumberOfSides(int noOfSides) const{
	//prints the shapes that match the number of sides given as param
	std::vector<Shape> shapes = getShapes();
	int amountOfMatchingShapes = 0;
	std::cout << "SHAPES WITH " << noOfSides << " SIDE(s): " << std::endl;
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		if (it->noOfSides == noOfSides)
		{
			it->print();
			amountOfMatchingShapes++;
		}
	}
	if (amountOfMatchingShapes == 0)
	{
		std::cout << "No Shapes with " << noOfSides << " sides!" << std::endl;
	}
	std::cout << "\n";
	return 0;
}//printShapesThatMatchSides

int ShapeSorter::printAreasDesc() const
{
	// prints the shapes in order of descending areas

	std::vector<Shape> shapes = getShapes();
	
	std::sort(shapes.begin(), shapes.end(), sortByArea);

	std::cout << "AREAS IN DESCENDING ORDER: \n";

	for (int i = 0; i != shapes.size(); i++)
	{
		shapes[i].print();
	}
	std::cout << "\n";
	return 0;
}//printAreasDesc

int ShapeSorter::printPerimeterDesc() const
{
	// prints the shapes in order of descending perimeters

	std::vector<Shape> shapes = getShapes();
	
	std::sort(shapes.begin(), shapes.end(), sortByPerimeter);
	std::cout << "PERIMETERS IN DESCENDING ORDER: \n";

	for (int i = 0; i != shapes.size(); i++)
	{
		shapes[i].print();
	}
	std::cout << "\n";
	return 0;
}//printPerimeterDesc
