
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
#include<cmath> 

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This body file defines the circle class 
*/
	
double Circle::get_Area()
{
	const double PI=4.*atan(1.); //calculate value for pi  
	return PI*m_radius*m_radius;
}	
double Circle::get_Perimeter()
{
	const double PI=4.*atan(1.); // calculate value for pi 
	return 2.*PI*m_radius;
}	

