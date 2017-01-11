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
std::string Shape::get_Name()
{
	return m_name_Of_Shape;
}
int Shape::get_Num_Sides()	
{
	return m_num_Sides;
}
void Shape:: report_Shape()
{
	std::cout<<std::setprecision(5);
	std::cout<<get_Name()<<"    "<<get_Num_Sides()<<"            "<<get_Area()<<"    "<<get_Perimeter()<<std::endl;
}
void Shape:: report_Headers()
{
	std::cout<<"name"<<"      "<<"# of sides"<<"      "<<"area"<<"      "<<"perimeter"<<std::endl;
}
