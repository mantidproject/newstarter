


#include <iostream>		//std::cout, std::cin

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
	
	std::vector< std::unique_ptr<Shape> > shapeVector;	//vector containing unique pointers to shape class oblects


	shapeVector.push_back(std::unique_ptr<Shape>(new Square(2)));		//add unique pointer to square object to shapeVector
	shapeVector.push_back(std::unique_ptr<Shape>(new Circle(3)));		//add unique pointer to circle object to shapeVector
	shapeVector.push_back(std::unique_ptr<Shape>(new Rectangle(4,5)));	//add unique pointer to rectangle object to shapeVector
	shapeVector.push_back(std::unique_ptr<Shape>(new IsoTriangle(2,3)));//add unique pointer to isosceles-triangle object to shapeVector

	ShapeSorter polysort(std::move(shapeVector));	//initialise shapesorter with shapeVector

	polysort.printOrderForPerim();			//display shapes ordered by perimeter
	polysort.printOrderForArea();			//display shapes ordered by area
	polysort.printMatchForSide(3);			//show matches, if any, for shape with number of sides '3' in shapeVector
	polysort.printMatchForType("triangle");	//show matches, if any, for shape with type similar to or exactly 'triangle' in shapeVector

	std::cin.get(); //wait for user input before terminating.

	return 0;
}
