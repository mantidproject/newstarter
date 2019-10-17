#include "../include/ShapeSorter.h"
#include <iostream>
/** Constructor
 * Empty constructor
 */
ShapeSorter::ShapeSorter() {};
/** Constructor with input list of shapes
 * @param shapeList : Input list of shapes to be stored in ShapeSorter
 */
ShapeSorter::ShapeSorter(std::vector<BaseShape*> shapeList) : m_shapeList(std::move(shapeList)) {}
/** 
 * Prints the names of the shapes stored in the object
 */
void ShapeSorter::PrintShapeNames() const{

    if (!this->m_shapeList.empty())
    {
        for (const auto& shape : this->m_shapeList)
        {
            std::cout << shape->getShapeName() << std::endl; 
        }
    }
}
/** Prints shape that match the input name
 * @param type: Shape type to search in object for
 */
void ShapeSorter::printShapeByType(const std::string& type) const
{
    if (! this->m_shapeList.empty())
    {
        std::cout << "Shapes matching specified type:" << std::endl;
        for (const auto& shape : this->m_shapeList)
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
/** Prints shape that match the number of sides
 * @param nSides: Number of sides
 */
void ShapeSorter::printShapeBySides(const int nSides) const
{
    if (! this->m_shapeList.empty())
    {
        std::cout << "Shapes matching specified number of sides:" << std::endl;
        for (const auto& shape : this->m_shapeList)
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
/**
 * Prints shapes by area
 */
void ShapeSorter::printShapesByArea() {

    if (! this->m_shapeList.empty())
    {
       // Sort shapes by area
       std::cout << "Sorting by area" << std::endl;
       std::sort(m_shapeList.begin(),m_shapeList.end(),
       [] (const BaseShape* a, const  BaseShape* b){
           return (a->getArea() > b->getArea());
       });
        // Print sorted shapes
       for (const auto& shape : this->m_shapeList)
        {
            std::cout << shape->getShapeName() << "Area:" << shape->getArea() << std::endl; 
        }        
    }
}
/**
 * Prints shapes by perimeter
 */
void ShapeSorter::printShapesByPerimeter() {

    if (! this->m_shapeList.empty())
    {
        // Sort shapes by perimeter
       std::cout << "Sorting by perimeter" << std::endl;
       std::sort(m_shapeList.begin(),m_shapeList.end(),
       [] (const BaseShape* a, const BaseShape* b){
           return (a->getPerimeter() > b->getPerimeter());
       });
        // Print sorted shapes
       for (const auto& shape : this->m_shapeList)
        {
            std::cout << shape->getShapeName() << "Perimeter:" << shape->getPerimeter() << std::endl; 
        }      
    }
}