#ifndef RECTANGLE_H
#define RECTANGLE_H

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
This header file defines the rectangle class 
*/
class Rectangle : public Shape // inhert shape
{
	private:
		double m_length1, m_length2; 
	public:
		// the constructor are for the special case of a rectange (square). 
		Rectangle(std::string name,double length1, double length2):Shape(name,4),m_length1(length1),m_length2(length2){}
		// normal definitions 
	
		Rectangle(double length1, double length2):Shape("rectangle",4),m_length1(length1),m_length2(length2){}
		~ Rectangle(){};
		double getArea() const override;	
		double getPerimeter()const  override;	

};

#endif
