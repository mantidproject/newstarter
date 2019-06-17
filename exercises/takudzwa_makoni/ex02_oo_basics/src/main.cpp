


#include <iostream>
#include <cctype>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "isoTriangle.h"
#include "circle.h"
#include "shapeSorter.h"

std::string circle::m_name = "CIRCLE";
std::string square::m_name = "SQUARE";
std::string rectangle::m_name = "RECTANGLE";
std::string isoTriangle::m_name = "ISOSCELES-TRIANGLE";

int main() {
	

	std::vector< std::unique_ptr<shape> > shapeVector;

	shapeVector.push_back(std::unique_ptr<shape>(new square(2)));
	shapeVector.push_back(std::unique_ptr<shape>(new circle(3)));
	shapeVector.push_back(std::unique_ptr<shape>(new rectangle(4,5)));
	shapeVector.push_back(std::unique_ptr<shape>(new isoTriangle(2,3)));

	//shapeVector.push_back(std::make_unique<square>(2));
	shapeSorter polysort(std::move(shapeVector));


	polysort.printOrderForPerim();
	polysort.printOrderForArea();
	polysort.printMatchForSide(3);
	polysort.printMatchForType("triangle");

	std::cin.get();

	return 0;
}
