#include "../include/ShapeSorter.h"



// *************************************************//
//Shape sorter
//Constructors
ShapeSorter::ShapeSorter()
{

};
// Constructor with input list of shapes
ShapeSorter::ShapeSorter(const std::vector<std::shared_ptr<BaseShape>>& shapeList)
{
    this->m_shapeList = shapeList;
}

// Print out the names of the shapes stored in the ShapeSorter object
void ShapeSorter::PrintShapeNames() const{

    if (!this->m_shapeList.empty())
    {
        for (auto shape : this->m_shapeList)
        {
            std::cout << shape->getShapeName() << std::endl; 
        }
    }
}

// Print shapes that matches input type
void ShapeSorter::printShapeByType(const std::string& type) const
{
    if (! this->m_shapeList.empty())
    {
        std::cout << "Shapes matching specified type:" << std::endl;
        for (auto shape : this->m_shapeList)
        {
            if ( shape->getShapeName().compare(type) == 0 )
            {
                 std::cout << shape->getShapeName() <<": ";
                 shape->printShapeDimensions();
                 std::cout << std::endl; 

            }
        }

    }

}

// Print shapes that match the input number of sides
void ShapeSorter::printShapeBySides(const int nSides) const
{
    if (! this->m_shapeList.empty())
    {
        std::cout << "Shapes matching specified number of sides:" << std::endl;
        for (auto shape : this->m_shapeList)
        {
            if ( shape->getNumSides() == nSides)
            {
                 std::cout << shape->getShapeName() <<": ";
                 shape->printShapeDimensions();
                 std::cout << std::endl; 

            }
        }

    }
}



// Function to sort shapes by area
void ShapeSorter::printShapesByArea() {

    if (! this->m_shapeList.empty())
    {

        // Sort shapes by area
       std::cout << "Sorting by area" << std::endl;
       std::sort(m_shapeList.begin(),m_shapeList.end(),
       [] (const std::shared_ptr<BaseShape>& a, const  std::shared_ptr<BaseShape>& b){

           return (a->getArea() > b->getArea());

       });
        // Print sorted shapes
       for (auto shape : this->m_shapeList)
        {
            std::cout << shape->getShapeName() << "Area:" << shape->getArea() << std::endl; 
        }
        

    }

}
// Function to sort shapes by perimeter
void ShapeSorter::printShapesByPerimeter() {

    if (! this->m_shapeList.empty())
    {
        // Sort shapes by perimeter
       std::cout << "Sorting by perimeter" << std::endl;
       std::sort(m_shapeList.begin(),m_shapeList.end(),
       [] (const std::shared_ptr<BaseShape>& a, const  std::shared_ptr<BaseShape>& b){

           return (a->getPerimeter() > b->getPerimeter());

       });
        // Print sorted shapes
       for (auto shape : this->m_shapeList)
        {
            std::cout << shape->getShapeName() << "Perimeter:" << shape->getPerimeter() << std::endl; 
        }
        

    }

}