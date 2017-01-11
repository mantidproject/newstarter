#ifndef square_h
#define square_h

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
This header file defines the square class - a square with 2 equal lengths
*/
class Square : public Rectangle
{
	public:
		Square():Rectangle("square")
		{
		};
		Square(double lengtha):Rectangle("square",lengtha,lengtha)
		{
		};
		~ Square(){};

};

#endif
