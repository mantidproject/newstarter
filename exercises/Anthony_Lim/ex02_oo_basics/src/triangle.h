#ifndef triangle_h
#define triangle_h

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
This header file defines the triangle class 
*/
class Triangle : public Shape
{
	private:
		double m_base,m_height;
		
	public:
		Triangle():Shape("triangle",3) // chosen for a circle to have 0 sides -> shouble be infinity 
		{
			m_base = 0.0;
			m_height = 0.0;
		};
		Triangle(double basea,double heighta):Shape("triangle",3)
		{
			m_base = basea;
			m_height=heighta;
		};
		~ Triangle(){};
		virtual  double get_Area();	
		virtual  double get_Perimeter(); 	

};


#endif
