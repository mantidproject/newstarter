/********************************INCLUDES***********************************/


#include "Shape.h"
#include "ShapeSorter.h"


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>




/********************************CONSTRUCTORS*******************************/

ShapeSorter::ShapeSorter(){}

ShapeSorter::ShapeSorter(std::vector<Shape*> s){
	allShapes = s;
}

ShapeSorter::~ShapeSorter(){}

/*******************************MEMBER FUNCTIONS****************************/
void ShapeSorter::printByType(const std::string &type){
	std::cout << std::endl << "Sorting shapes by type: \"" << type << "\"..." << std::endl << std::endl;
	std::vector<Shape*> allShapes = getShapes();
	int printed = 0;
	for(int i = 0; i < allShapes.size(); i++){
		if((allShapes[i]->getType().compare(type)) == 0){
			allShapes[i]->print();
			printed++;
		}
	}
	if(printed == 0){
		std::cout << "No shapes were found that match the type: \""<< type << "\"" << std::endl;
	}
}

void ShapeSorter::printBySide(const int &sides){
	std::cout << std::endl << "Sorting shapes with \"" << sides << "\" sides..." << std::endl << std::endl;
	std::vector<Shape*> allShapes = getShapes();
	int printed = 0;
	for(int i = 0; i < allShapes.size(); i++){
		if(allShapes[i]->getSides() == sides){
			allShapes[i]->print();
			printed++;
		}
	}
	if(printed == 0){
		std::cout << "No shapes were found that have \""<< sides << "\" number of sides" << std::endl;
	}
}

static bool compareVolume(Shape* first, Shape* second){
	return first->getArea() > second->getArea();
}

static bool comaprePerimeter(Shape* first, Shape* second){
	return first->getPerimeter() > second->getPerimeter();
}


void ShapeSorter::printByVolume(){
	std::vector<Shape*> shapesByV = getShapes();
	std::sort(shapesByV.begin(), shapesByV.end(), compareVolume);
	printAll();
}

void ShapeSorter::printByPerimeter(){
	std::vector<Shape*> shapesByP = getShapes();
	std::sort(shapesByP.begin(), shapesByP.end(), comparePerimeter);
	printAll();
}

void ShapeSorter::printAll(){
	std::vector<Shape*> allShapes = getShapes();
	if(allShapes.size() == 0){
		std::cout << "The list of shapes is empty";
	}else{
		for(int i = 0; i < allShapes.size(); i++){
			allShapes[i]->print();
		}
	}

}




/***********************************ACCESSOR********************************/
std::vector<Shape*> ShapeSorter::getShapes()		{	return allShapes;	}

/***********************************MUTATORS********************************/
void ShapeSorter::updateShapes(const std::vector<Shape*> &s)	{allShapes = s;	}

/*********************************END OF FILE*******************************/