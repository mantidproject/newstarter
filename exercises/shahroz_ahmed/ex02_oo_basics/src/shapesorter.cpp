#include "shapesorter.h"
#include <string>
#include <vector>
#include <algorithm>    // std::sort
#include <iostream>

using namespace std;
bool wayToSort(int i, int j) { return i > j; }


ShapeSorter:: ShapeSorter(vector<Shape*> shapesort){
	this -> shapesort = shapesort;
};

vector<Shape*> ShapeSorter:: getVShape()const{
	return this -> shapesort;
};

void ShapeSorter:: printDetails(){
	std::vector<Shape*> shapesort = getVShape();
	for(int i=0; i<shapesort.size(); ++i){
		printf(shapesort[i]->getType().c_str(), " --> Number of Sides: " , shapesort[i]->getSides(), " --> Type: " , shapesort[i]->getPerimeter(), " --> Perimeter: ", shapesort[i]->getArea());
	}
};

void ShapeSorter:: printChosenType(string type){
	std::vector<Shape*> shapesort = getVShape();
	for(int i=0; i<shapesort.size(); ++i){
		while(shapesort[i]->getType() == type){//while the gettype == type inputted
			printDetails();
			
		}	
	}
};
void ShapeSorter:: printChosenNumber(int sides){
	std::vector<Shape*> shapesort = getVShape();
	for(int i=0; i<shapesort.size(); ++i){
		while(shapesort[i]->getSides() == sides){ //while the getsides == sides inputted
			printDetails();
		}	
	}
};
void ShapeSorter:: printVolumeDecending(){
	std::vector<Shape*> shapesort = getVShape();
	std::sort(shapesort.begin(), shapesort.end(), wayToSort);
	 for (Shape* n : shapesort)
		 cout << n.getArea() << " ";

};

void ShapeSorter:: printPerimeterDecending(){
	printf("[Perimeter: ");
};




/**
*formula used: 
*0 < p < sqrt ( 2 x width x width) + (4 x height x height)
*returns the aproximate perimeter of the triangle
*/