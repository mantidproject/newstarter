#ifndef shape_sorter_h
#define shape_sorter_h

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
#include<vector> 

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This header file defines the triangle class 
*/
class Shape_Sorter
{
	private:
		std::vector<Shape*> m_shapes;
		void swap(Shape* &shape1,Shape* &shape2);
	public: 
		Shape_Sorter(std::vector<Shape*> shapes_in)
		{
			m_shapes=shapes_in;
		};
		void get_Match_Shape(std::string this_shape);
		void match_Sides(int sides);
		void order_By_Area();
		void order_By_Perimeter();
};



#endif
