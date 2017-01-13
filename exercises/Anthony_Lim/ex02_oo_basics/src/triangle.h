#ifndef TRIANGLE_H
#define TRIANGLE_H

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
This header file defines the triangle class 
*/
class Triangle : public Shape
{
	private:
		double m_base,m_height;
		
	public:
		// chosen for a circle to have 0 sides -> shouble be infinity 
		Triangle(double base,double height):Shape("triangle",3),m_base( base),m_height(height){}
		~ Triangle(){};
		double GetArea() const override;	
		double GetPerimeter() const override; 	

};


#endif
