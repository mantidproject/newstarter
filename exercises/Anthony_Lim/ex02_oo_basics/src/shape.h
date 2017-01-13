#ifndef SHAPE_H
#define SHAPE_H

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

#include<string> 

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This header file defines the shape class - which is an abstract concept
*/
class Shape
{
	protected:
		std::string m_nameOfShape;
		int m_numSides;
	public:
		Shape(std::string name_in,int sides):m_nameOfShape(name_in), m_numSides(sides){	}
		virtual ~Shape(){};
		std::string GetName() const;
		int GetNumSides() const;
		virtual double GetArea() const =0;
		virtual double GetPerimeter() const =0;
		void ReportShape() const;
		void ReportHeaders() const;
};

#endif
