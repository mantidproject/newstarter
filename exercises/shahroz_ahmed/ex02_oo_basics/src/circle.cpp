#include "circle.h"

using namespace std;

double pi = 3.142;

Circle:: Circle(double radius): Shape("Circle", 1){
	this -> radius = radius;
};
//returns radius
double Circle :: getRadius(){
	return this -> radius; 
};
/**
*@parameter radius
*set radius
*/
void Circle ::setRadius(double radius){
	this -> radius = radius;

};
/**
*formula used: area = (pi = 3.142.....) x radius ^ 2
*returns the area of circle
*/
double Circle :: getArea() const{
	return pi*(this -> radius)*(this -> radius); 

};
/**
*formula used: perimeter = (2 x pi x r)
*returns the perimeter of circle
*/

double Circle :: getPerimeter() const{
	return 2* (pi*(this->radius)); 
}