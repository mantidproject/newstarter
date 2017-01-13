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
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "shape_sorter.h"

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
	std::vector<Shape*> shapes;	
	// create shapes 
	Square s1(3.1);
	shapes.push_back(&s1);
	
	Rectangle r1(2.2,3.);
	shapes.push_back(&r1);


	Triangle t1(4.,3.2);
	shapes.push_back(&t1);

	Circle c1(3.4);
	shapes.push_back(&c1);
	Circle c2(4.2);
	shapes.push_back(&c2); // include multiple circles 

	// use the shape sorter 
	ShapeSorter data(shapes);

	std::cout<<"list shapes with 4 sides"<<std::endl;
	c2.ReportHeaders(); // output the headers to screen 
	data.PrintMatchedSides(4);
	std::cout<<std::endl;
	
	
	std::cout<<"lists all circles"<<std::endl;
	c2.ReportHeaders(); // output the headers to screen 
	data.PrintMatchedShape("circle");
	std::cout<<std::endl;
	
	std::cout<<"Orders shapes by area"<<std::endl;
	c2.ReportHeaders(); // output the headers to screen 
	data.PrintOrderByArea();
	std::cout<<std::endl;
	
	std::cout<<"Orders shapes by perimeter"<<std::endl;
	c2.ReportHeaders(); // output the headers to screen 
	data.PrintOrderByPerimeter();
	
	
}
