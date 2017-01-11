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

/*
Aurthor: Anthony Lim
data: 10/01/2017
*/

/*
This body file is for the shape_sorter class 
*/
void Shape_Sorter::swap(Shape* &shape1, Shape* &shape2)
{
	Shape* tmp1 = shape1;
	Shape* tmp2 = shape2;
	shape1 = tmp2;
	shape2 = tmp1;
}
	
void Shape_Sorter::get_Match_Shape(std::string this_shape)
{
	for(int j =0;j<m_shapes.size();j++)
	{
		if(this_shape == m_shapes[j]->get_Name())
		{
			m_shapes[j]->report_Shape();
		}
	}	
}
void  Shape_Sorter::match_Sides(int sides)
{	
	for(int j =0;j<m_shapes.size();j++)
	{
		if(sides == m_shapes[j]->get_Num_Sides())
		{
			m_shapes[j]->report_Shape();
		}
	}	
}

// this method and the method below could be merged, however I did not know how to pass the method (area or perimeter) to the ordering method. 
// could have used a map to auto-order the data. However, some data would be lost. 
void Shape_Sorter::order_By_Area()
{	//order results
	for(int k =0;k<m_shapes.size();k++)
	{
		for(int j =0;j<m_shapes.size()-1;j++)
		{
			if(m_shapes[j]->get_Area()<m_shapes[j+1]->get_Area() )
			{
				swap(m_shapes[j],m_shapes[j+1]);	
			}
		}
	}
	//print results
	for(int j =0;j<m_shapes.size();j++)
	{
		m_shapes[j]->report_Shape();
		
	}	

}
void Shape_Sorter::order_By_Perimeter()
{	//order results
	for(int k =0;k<m_shapes.size();k++)
	{
		for(int j =0;j<m_shapes.size()-1;j++)
		{
			if(m_shapes[j]->get_Perimeter()<m_shapes[j+1]->get_Perimeter() )
			{
				swap(m_shapes[j],m_shapes[j+1]);	
			}
		}
	}
	// print results
	for(int j =0;j<m_shapes.size();j++)
	{
		m_shapes[j]->report_Shape();
	}	
}


