#ifndef circle_h
#define circle_h

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

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This header file defines the circle class 
*/
class Circle : public Shape
{
	private:
		double m_radius;
		
	public:
		// chosen for a circle to have 0 sides -> shouble be infinity 
		Circle(double radius):Shape("circle",0),m_radius(radius){}
		~ Circle(){};
		double GetArea() const override;	
		double GetPerimeter() const override;	

};

#endif
