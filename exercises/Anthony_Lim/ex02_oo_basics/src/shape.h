#ifndef shape_h
#define shape_h

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
		std::string m_name_Of_Shape;
		int m_num_Sides;
	public:
		Shape(std::string name_in, int sides)
		{
			m_name_Of_Shape=name_in;
			m_num_Sides=sides;
		};
		~Shape(){};
		std::string get_Name();
		int get_Num_Sides();
		virtual double get_Area()=0;
		virtual double get_Perimeter()=0;
		void report_Shape();
		void report_Headers();
};

#endif
