#include "rectangle.h"

using namespace std;

Rectangle:: Rectangle(double height, double width): Shape("Rectangle", 4){
	this -> height = height;
	this -> width = width;
}
//returns width
double Rectangle::GetWidth(){
	return this -> width;
};
//returns height
double Rectangle:: GetHeight(){
	return this -> height;
};

/**
*@parameter width
*set width
*/
void Rectangle:: SetWidth(double width){
	this -> width;
};
/**
*@parameter height
*set height
*/
void Rectangle:: SetHeight(double height){
	this -> height;
};
//returns area of the rectangle
double Rectangle:: getArea()const{
	return height*width;
};
//returns perimeter of the rectangle
double Rectangle:: getPerimeter() const{
	return (2*width)+(2*height);
};