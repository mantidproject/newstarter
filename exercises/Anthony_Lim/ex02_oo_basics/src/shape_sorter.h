#ifndef SHAPE_SORTER_H
#define SHAPE_SORTER_H

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
#include<vector> 

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This header file defines the shape sorter class 
*/
class ShapeSorter
{
	private:
		std::vector<Shape*> m_shapes;
	public: 
		ShapeSorter(std::vector<Shape*> shapes):m_shapes(shapes){}
		~ShapeSorter(){};
		void printMatchedShape(std::string this_shape) const;
		void printMatchedSides(int sides) const;
		void printOrderByArea();
		void printOrderByPerimeter();
};



#endif
