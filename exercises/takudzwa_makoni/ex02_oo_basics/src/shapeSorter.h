#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <memory>		//std::unique_ptr
#include <vector>		//std::vector
#include <cctype>		//std::toupper
#include <algorithm>	//std::transform, std::sort
#include <ostream>		//std:: ostream operator
#include <iostream>
#include "shape.h"

class ShapeSorter {

public:

	ShapeSorter(std::vector<std::unique_ptr<Shape>>&& shapesContainer);

	void printMatchForSide(int chosenNumOfSides) const;
	void printMatchForType(std::string chosenType) const; 
	void printOrderForArea() ;
	void printOrderForPerim() ;  

private:

	std::vector<std::unique_ptr<Shape>> m_shapes;
	
};

#endif
