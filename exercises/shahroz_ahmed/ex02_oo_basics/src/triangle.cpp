#include "triangle.h"
#include "shape.h"
#include<cmath>
using namespace std;

Triangle:: Triangle(double height, double width): Shape("Triangle", 3){
	this -> height = height;
	this -> width = width;

};
//returns height
double Triangle:: getHeight(){
	return this -> height;
};
//returns width
double Triangle:: getWidth(){
	return this -> width;
};
/**
*@parameter height
*set height
*/
void Triangle:: setHeight(double height){
	this -> height; 
};

/**
*@parameter width
*set width
*/
void Triangle:: setWidth(double width){
	this -> width;
};
/**
*returns the area of triangle
*/
double Triangle:: getArea() const{
	return (height*width)/2;
};
/**
*formula used: 
*0 < p < sqrt ( 2 x width x width) + (4 x height x height)
*returns the aproximate perimeter of the triangle
*/
double Triangle:: getPerimeter()const{
	
	return this-> width + sqrt(((this->width*this->width)/4) + (this->height*this->height));
};