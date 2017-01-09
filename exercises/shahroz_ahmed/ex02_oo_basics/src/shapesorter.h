#ifndef SHAPESORTER_H
#define SHAPESORTER_H
#include "shape.h"
#include <vector>

class ShapeSorter
{
	
private:
	vector<Shape*> shapesort;
public:
	ShapeSorter(vector<Shape*> shapesort);
	void printDetails();
	vector<Shape*> getVShape()const;
	void printChosenType(string type);
	void printChosenNumber(int sides);
	void printVolumeDecending();
	void printPerimeterDecending();
	
};

#endif