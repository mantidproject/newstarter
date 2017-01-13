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

#include "triangle.h" 
#include<string> 
#include<cmath> // this is math.h 

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This body file is for the triangle class 
*/
double Triangle::GetArea() const 
{
	return m_base*m_height/2.;
}	
double Triangle::GetPerimeter() const
{
	return m_base+2.*sqrt((m_height*m_height)+((m_base*m_base)/4));
} // this is from the mantid introduction to c++ webpage => assumes isoceles triangle 	

