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
#include "rectangle.h"
#include<string> 

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This body file defines the rectangle class 
*/
double Rectangle::GetArea() const 
{
	return m_length1*m_length2;
}	
double Rectangle::GetPerimeter() const 
{
	return 2.*(m_length1+m_length2);
}	

