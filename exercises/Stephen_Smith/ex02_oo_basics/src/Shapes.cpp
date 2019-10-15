#include "../include/Shapes.h"



// *************************************************//
// Base shape
// // Constructor
BaseShape::BaseShape(){};

// Destructor
BaseShape::~BaseShape(){};

// Getters
double BaseShape::getArea() const{
    return this->m_area;
}
double BaseShape::getPerimeter() const
{
    return this->m_perimeter;
}

// *************************************************//
// Circle
//
const int Circle::NUMSIDES = 1;
const std::string Circle::SHAPENAME =std::string("Circle");


// Circle constructors
Circle::Circle()
{
    this->m_radius = 0.0;
    this->m_area=0.0;
    this->m_perimeter = 0.0;
}
Circle::Circle(const double radius)
{
    // Set radius
    this->m_radius = radius; 
    // Set area
    this->setArea(this->calculateArea());
    // Set perimeter
    this->setPerimeter(this->calculatePerimeter());
}


// Print circle dimensions
void Circle::printShapeDimensions() const
{
    std::cout << "Radius=" << this->m_radius;
}

// Return shape name and number of sides
int Circle::getNumSides() const
{
    return this->NUMSIDES;

}
// Shape name 
std::string Circle::getShapeName() const{
    return this->SHAPENAME;
}

// *************************************************//
//Rectangle
const int Rectangle::NUMSIDES = 4;
const std::string Rectangle::SHAPENAME =std::string("Rectangle");


// Rectangle constructors
Rectangle::Rectangle()
{
    this->m_depth = 0.0;
    this->m_width = 0.0;
    this->setArea(0.0);
    this->setPerimeter(0.0);
  
}
Rectangle::Rectangle(const double width, const double depth)
{
    // set width and depth
    this->m_depth = depth;
    this->m_width = width;

    // Set area
    this->setArea(this->calculateArea());
    // Set perimeter
    this->setPerimeter(this->calculatePerimeter());

}


// Print shape dimensions
void Rectangle::printShapeDimensions() const
{
    std::cout << "Width=" << this->m_width << "   Depth=" << this->m_depth;
}

// Return shape name and number of sides
int Rectangle::getNumSides() const
{
    return this->NUMSIDES;

}
// Shape name 
std::string Rectangle::getShapeName() const{
    return this->SHAPENAME;
}

// *************************************************//
//Square

const int Square::NUMSIDES = 4;
const std::string Square::SHAPENAME =std::string("Square");


// Square constructors
// Default construcor -- initialise length to zero 
Square::Square()
{
    this->m_sideLength = 0.0;
    this->setArea(0.0);
    this->setPerimeter(0.0);
}

// Constructor
// Input param = square length
Square::Square(const double sideLength)
{
    // Set side length
    this->m_sideLength = sideLength;

    // Set area
    this->setArea(this->calculateArea());
    // Set perimeter
    this->setPerimeter(this->calculatePerimeter());

}


// Print square dimensions
void Square::printShapeDimensions() const
{
    std::cout << "Side length =" << this->m_sideLength;

}

// Return shape name and number of sides
int Square::getNumSides() const
{
    return this->NUMSIDES;

}
// Shape name 
std::string Square::getShapeName() const{
    return this->SHAPENAME;
}

// *************************************************//
//Triangle
const int Triangle::NUMSIDES = 3;
const std::string Triangle::SHAPENAME =std::string("Triangle");


// Square constructors
// Default construcor -- initialise length and area to zero 
Triangle::Triangle()
{
    this->m_base = 0.0;
    this->m_height = 0.0;
    this->setArea(0.0);
    this->setPerimeter(0.0);
}

// Constructor
// Input param = side length of square
Triangle::Triangle(const double base, const double height)
{
    // Set base and height
    this->m_base = base;
    this->m_height =height;

    // Set area
    this->setArea(this->calculateArea());
    // Set perimeter
    this->setPerimeter(this->calculatePerimeter());
}

// Print shape dimensions
void Triangle::printShapeDimensions() const
{
    std::cout << "Base=" << this->m_base << "   Height=" << this->m_height;
}

// Return shape name and number of sides
int Triangle::getNumSides() const
{
    return this->NUMSIDES;

}
// Shape name 
std::string Triangle::getShapeName() const{
    return this->SHAPENAME;
}
