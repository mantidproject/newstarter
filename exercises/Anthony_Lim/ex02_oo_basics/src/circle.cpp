
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
#include "circle.h"
#include<string> 
#include<cmath> //this is math.h

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This body file defines the circle class 
*/
	
double Circle::getArea() const 
{
	return M_PI*m_radius*m_radius;
}	
double Circle::getPerimeter() const  
{
	return 2.*M_PI*m_radius;
}	

