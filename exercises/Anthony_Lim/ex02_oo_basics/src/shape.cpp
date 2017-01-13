//This is the introduction exercise 2. The work has been completed by Anthony Lim 
/*
------------------------------------------------------------------------------
Include statements:

 	internal headers - same project
 	internal headers - different project
 	3rd part headers
	system
-------------------------------------------------------------------------------
*/

#include "shape.h" 
#include<string> 
#include<iostream> 
#include<iomanip>
/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This body file is for the shape class - which is an abstract concept
*/
std::string Shape::getName()  const
{
	return m_nameOfShape;
}
int Shape::getNumSides() const	
{
	return m_numSides;
}
void Shape:: reportShape() const
{
	std::cout<<std::setprecision(5);
	std::cout<<getName()<<"    "<<getNumSides()<<"            "<<getArea()<<"    "<<getPerimeter()<<std::endl;
}
void Shape:: reportHeaders() const
{
	std::cout<<"name"<<"      "<<"# of sides"<<"      "<<"area"<<"      "<<"perimeter"<<std::endl;
}
