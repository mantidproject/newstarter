/*std::string type;
int sides;
double area, perimeter, height, width;*/


#include "Shape.h"
#include <string>

Shape::Shape(std::string t, int s){
	type = t;
	sides = s;
}

Shape::~Shape(){

}

std::string Shape::getType(){
	return type;
}

int Shape::getSides(){
	return sides;
}

double Shape::getArea(){
	return area;
}

double Shape::getPerimiter(){
	return perimeter;
}



