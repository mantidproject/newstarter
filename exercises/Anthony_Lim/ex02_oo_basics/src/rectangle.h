#ifndef rectangle_h
#define rectangle_h

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
		// the first two constructors are for the special case of a rectange (square). 
		Rectangle(std::string name):Shape(name,4)
		{
			m_length1 = 0.0;
			m_length2 = 0.0;
		};
		Rectangle(std::string name,double lengtha, double lengthb):Shape(name,4)
		{
			m_length1 = lengtha;
			m_length2 = lengthb;
		};
		// normal definitions 
		Rectangle():Shape("rectangle",4)
		{
			m_length1 = 0.0;
			m_length2 = 0.0;
		};
	
		Rectangle(double lengtha, double lengthb):Shape("rectangle",4)
		{
			m_length1 = lengtha;
			m_length2 = lengthb;
		};
		~ Rectangle(){};
		virtual  double get_Area();	
		virtual  double get_Perimeter();	

};

#endif
