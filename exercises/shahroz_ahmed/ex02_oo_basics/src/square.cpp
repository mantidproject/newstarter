#include "square.h"
using namespace std;

Square::Square(double side) : Shape("Square", 4){
	this->side = side;
	this -> perimeter = getPerimeter();
	//this -> area = getArea();
};
//returns side
double Square::GetSide() {
	return this->side;
};
/**
*@parameter side
*set side
*/
void Square::SetSide(double size) {
	this -> side = size;
};
/**
*returns the area of square
*/
double Square::getArea()const{
	return this->side * this -> side;
};
/**
*returns the perimeter of square
*/
double Square::getPerimeter()const{
    return this->side * 4;
};
