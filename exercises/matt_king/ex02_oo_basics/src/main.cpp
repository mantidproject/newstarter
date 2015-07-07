/**
* Skeleton main routine
*/
#include <iostream>
#include <vector>
#include <string>

#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

template <class S>class ShapeSorter{
public:
	ShapeSorter();
	std::string printShapesThatMatchType(std::string type, std::vector shapes) const{};
	std::string printShapesThatMatchSides(int sides, std::vector shapes) const{};
	std::string printAreasDesc(std::vector shapes) const{};
	std::string printPerimeterDesc(std::vector shapes) const{};
private:
	bool compare(S thisShape, S anotherShape){};
};


int main(int, char **)
{
	//Circle circle("Circle", 5);
	//Square square("Square", 3);
	//new Rectangle("Rectangle", 7, 2);
	Triangle tri(4, 2);
	Circle circ(7);
	Square square(23.3);
	Rectangle rect(4, 5);
	
	std::vector<Shape> shapes;

	shapes.push_back(tri);
	shapes.push_back(circ);
	shapes.push_back(square);
	shapes.push_back(rect);

	for (auto it = shapes.begin(); it != shapes.end(); ++it)
	{
		std::cout << it->getType().c_str() << std::endl;
	}
	
	
}