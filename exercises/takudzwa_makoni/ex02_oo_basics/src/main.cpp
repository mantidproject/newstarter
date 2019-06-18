


#include <iostream>		//std::cout, std::cin
//#include <cctype>
//#include <math.h>
//#include <stdio.h>
//#include <ctype.h>
//#include <locale>
//#include <utility>
#include <vector>		//std::vector
#include <string>		//std::string
#include <algorithm>	//std::transform
#include <memory>		//std::unique_ptr

#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "isoTriangle.h"
#include "circle.h"
#include "shapeSorter.h"

const std::string circle::m_name = "CIRCLE";
const std::string square::m_name = "SQUARE";
const std::string rectangle::m_name = "RECTANGLE";
const std::string isoTriangle::m_name = "ISOSCELES-TRIANGLE";

int main() {
	

	std::vector< std::unique_ptr<shape> > shapeVector;

	shapeVector.push_back(std::unique_ptr<shape>(new square(2)));
	shapeVector.push_back(std::unique_ptr<shape>(new circle(3)));
	shapeVector.push_back(std::unique_ptr<shape>(new rectangle(4,5)));
	shapeVector.push_back(std::unique_ptr<shape>(new isoTriangle(2,3)));

	shapeSorter polysort(std::move(shapeVector));

	polysort.printOrderForPerim();
	polysort.printOrderForArea();
	polysort.printMatchForSide(3);
	polysort.printMatchForType("triangle");

	std::cin.get();

	return 0;
}
