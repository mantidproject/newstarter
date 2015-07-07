#ifndef SHAPESORTER_H
#define	SHAPESORTER_H

//Includes
#include "Shape.h"

#include <vector>


//Class definition
class ShapeSorter{
public:
	ShapeSorter();
	ShapeSorter(std::vector<Shape*> s);
	~ShapeSorter();
	void printByType(const std::string &type);
	void printBySide(const int &sides);
	void printByVolume();
	void printByPerimeter();
	void updateShapes(const std::vector<Shape*> &s);
	void printAll();
	std::vector<Shape*> getShapes();
	static bool compareVolume(Shape * first, Shape * second);
	static bool comparePerimeter(Shape * first, Shape * second);

private:
	std::vector<Shape*> allShapes;
};
#endif SHAPESORTER_H 
//End of File