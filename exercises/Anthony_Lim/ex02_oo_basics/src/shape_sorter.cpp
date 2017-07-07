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

#include "shape_sorter.h" 
#include<string> 
#include<algorithm> 
/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This body file is for the shape_sorter class 
*/
void ShapeSorter::printMatchedShape(std::string this_shape) const 
{
	for(int j =0;j<m_shapes.size();j++)
	{
		if(this_shape == m_shapes[j]->getName())
		{
			m_shapes[j]->reportShape();
		}
	}	
}
void  ShapeSorter::printMatchedSides(int sides) const
{	
	for(const auto tmpShape:m_shapes )
	{
		if(sides == tmpShape->getNumSides())
		{
			tmpShape->reportShape();
		}
	}	
}

// this method and the method below could be merged, however I did not know how to pass the method (area or perimeter) to the ordering method. 
// could have used a map to auto-order the data. However, some data would be lost. 
void ShapeSorter::printOrderByArea()
{	//order results
	for(auto k:m_shapes ) // using std::Sort causes problems with the comparison as we wnat to move the object but just compare one particular method => done it explicitly. 
	{
		for(int j =0;j<m_shapes.size()-1;j++)
		{
			if(m_shapes[j]->getArea()<m_shapes[j+1]->getArea() )
			{
				std::swap(m_shapes[j],m_shapes[j+1]);	
			}
		}
	}
	//print results
	for(const auto tmpShape:m_shapes )
	{
		tmpShape->reportShape();
	}	

}
void ShapeSorter::printOrderByPerimeter()
{	//order results
	for(auto k:m_shapes )
	{
		for(int j =0;j<m_shapes.size()-1;j++)
		{
			if(m_shapes[j]->getPerimeter()<m_shapes[j+1]->getPerimeter() )
			{
				std::swap(m_shapes[j],m_shapes[j+1]);	
			}
		}
	}
	// print results
	for(const auto tmpShape:m_shapes )
	{
		tmpShape->reportShape();
	}	
}


