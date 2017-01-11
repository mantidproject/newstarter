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
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "shape_sorter.h"

//#include<string> 


#include<vector> 
#include<string> 
#include<iostream> 
#include<cmath> 

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This is the main file where computations are done
*/
int main(int, char **)
{
	std::vector<Shape*> m_shapes;	
	// create shapes 
	Square m_s1(3.1);
	m_shapes.push_back(&m_s1);
	
	Rectangle m_r1(2.2,3.);
	m_shapes.push_back(&m_r1);


	Triangle m_t1(4.,3.2);
	m_shapes.push_back(&m_t1);

	Circle m_c1(3.4);
	m_shapes.push_back(&m_c1);
	Circle m_c2(4.2);
	m_shapes.push_back(&m_c2); // include multiple circles 

	// output the headers to screen 
	m_c2.report_Headers();
	
	// use the shape sorter 
	Shape_Sorter m_data(m_shapes);

	std::cout<<"lists all circles"<<std::endl;
	m_data.get_Match_Shape("circle");
	std::cout<<std::endl;
	std::cout<<"Orders shapes by area"<<std::endl;
	m_data.order_By_Area();
	std::cout<<std::endl;
	std::cout<<"Orders shapes by perimeter"<<std::endl;
	m_data.order_By_Perimeter();
	
	
}
