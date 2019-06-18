


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
#include <ostream>		//std::ostream

#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "isoTriangle.h"
#include "circle.h"
#include "shapeSorter.h"




//bool comparePerim(const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) ;
//bool compareArea(const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) ;




int main() {
	



	std::vector< std::unique_ptr<Shape> > shapeVector;


	shapeVector.push_back(std::unique_ptr<Shape>(new Square(2)));
	shapeVector.push_back(std::unique_ptr<Shape>(new Circle(3)));
	shapeVector.push_back(std::unique_ptr<Shape>(new Rectangle(4,5)));
	shapeVector.push_back(std::unique_ptr<Shape>(new IsoTriangle(2,3)));

	ShapeSorter polysort(std::move(shapeVector));

	polysort.printOrderForPerim();
	polysort.printOrderForArea();
	polysort.printMatchForSide(3);
	polysort.printMatchForType("triangle");

	std::cin.get();

	return 0;
}
