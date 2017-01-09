#include "shape.h"
#include <string>

//base class
using namespace std;

Shape:: Shape(string name, int sides){
	this -> name = name;
	this -> sides = sides;

}
//set the type name
void Shape:: setType(string name){
	this -> name = name;
}
//get the type
string Shape:: getType()const{
	return this -> name;
}
//set the number of sides
void Shape:: setSides(int sides){
	this -> sides = sides;
}
//get the number of sides
int Shape:: getSides()const{
	return this -> sides;
}

double Shape:: getArea()const{
	return 0;
}

double Shape:: getPerimeter()const{
	return 0;
};



