//
//  ShapeSorter.cpp
//  Tutorials
//
//  Created by Keith Butler on 15/02/2018.
//  Copyright © 2018 Keith Butler. All rights reserved.
//

#include <string>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include <vector>

using std::cout; using std::vector; using std::string;

//  This sets up the shape class, which will be used by
//  rectangle, square, triangle and circle.
class Shape
{
    public:
    virtual string type() const = 0;
    virtual int number_sides() const = 0;
    virtual float perimeter() const = 0;
    virtual float area() const = 0;
};

// Define the rectangle class
// It will take two sides as properties
// It can calculate permieter and area
// It knows that it is 'Rectangle'
class Rectangle : public Shape 
{
    public:
    float length;
    float width;
    Rectangle(float l, float w) {length = l; width = w; 
// include some error handeling
    if (width < 0){
        string errorMsg = "Width of a rectangle must be greater than or equal to 0.";
        throw std::invalid_argument(errorMsg);
    }    
    else if (length < 0) {
        string errorMsg = "Length of a rectangle must be greater than or equal to 0.";
        throw std::invalid_argument(errorMsg);
    }
    }
// back to the rest of the class definitions    
    string type() const { return "Rectangle"; }
    int number_sides() const { return 4; }
    float perimeter() const { return 2*length + 2*width; }
    float area() const { return length*width; }
};

// Define the square class
// It will take one side as a property
// It can calculate permieter and area
// It knows that it is 'Square'
class Square : public Shape 
{
    public:
    float length;
    Square(float l) {length = l; 
// include some error handeling
    if (length < 0){
        string errorMsg = "Dimension of a square must be greater than or equal to 0.";
        throw std::invalid_argument(errorMsg);
    }    
    }
    string type() const { return "Square"; }
    int number_sides() const { return 4; }
    float perimeter() const { return 4*length; }
    float area() const { return length*length; }
};

// Define the circle class
// It will take a radius as a property
// It can calculate permieter and area
// It knows that it is 'Circle'
class Circle : public Shape 
{
    public:
    float radius;
    Circle(float r) {radius = r;
// include some error handeling
    if (radius < 0){
        string errorMsg = "Radius of a circle must be greater than or equal to 0.";
        throw std::invalid_argument(errorMsg);
    }    
    }
    string type() const { return "Circle"; }
    int number_sides() const { return 1; }
    float perimeter() const { return 2*M_PI*radius; }
    float area() const { return M_PI*radius*radius; }
};


// Define the triangle class
// It will take base and height as properties
// It can calculate permieter and area
// It knows that it is 'Triangle'
class Triangle : public Shape 
{
    public:
    float base;
    float height;
    Triangle(float b, float h) {height = h; base = b; 
// include some error handeling
    if (height < 0){
        string errorMsg = "Height of a triangle must be greater than or equal to 0.";
        throw std::invalid_argument(errorMsg);
    }    
    else if (base < 0) {
        string errorMsg = "Base of a triangle must be greater than or equal to 0.";
        throw std::invalid_argument(errorMsg);
    }
    }
// back to the rest of the class definitions    
    string type() const { return "Triangle"; }
    int number_sides() const { return 3; }
    float perimeter() const { return base + 2*sqrt(height*height + base*base/4); }
    float area() const { return base/2 * height; }
};

// Set up functions to sort shapes by various attributes
// 1 Type

// isShape compares the shape against a target
// args:
// shape_target: a string
// shape_provided: a string
bool isShape(string shape_provided, string shape_target){
    return shape_target == shape_provided;
}

// hasSides compares the shape against a target number of sizes
// args:
// shape_target: an int
// shape_provided: an int
bool hasSides(int shape_target, int shape_provided){
    return shape_target == shape_provided;
}

// A function to determine which shape has the larger area
// Args:
// shape1: a shape
// shape2: a shape
// Returns:
// boolian, is shape1 larger than shape2?
bool greaterArea( const Shape* shape1, const Shape* shape2){return shape1-> area() 
    > shape2 -> area(); }

// A function to determine which shape has the larger perimeter
// Args:
// shape1: a shape
// shape2: a shape
// Returns:
// boolian, is shape1 larger than shape2?
bool greaterPerim( const Shape* shape1, const Shape* shape2){return shape1-> perimeter() 
    > shape2 -> perimeter(); }

// A function to sort a list of shapes by area
// Args:
// shapeList: a vector containing shapes
// Returns:
// Nothing, this is a void; prints out the sorted list
void sortArea(const vector<Shape*> &shapeList){
    vector<Shape*> sorted = shapeList;
    std::sort(sorted.begin(), sorted.end(), greaterArea);
    for(vector<Shape*>::const_iterator it = sorted.begin();
            it != sorted.end(); it++)
        cout << (*it)->area() << " " << (*it)->type() << "\n";
}

// A function to sort a list of shapes by perimeter
// Args:
// shapeList: a vector containing shapes
// Returns:
// Nothing, this is a void; prints out the sorted list
void sortPerim(const vector<Shape*> &shapeList){
    vector<Shape*> sorted = shapeList;
    std::sort(sorted.begin(), sorted.end(), greaterPerim);
    for(vector<Shape*>::const_iterator it = sorted.begin();
            it != sorted.end(); it++)
        cout << (*it)->perimeter() << " " << (*it)->type() << "\n";
}

// A function to print the details of a shape
// Args:
// shape: a shape
// Returns:
// Nothing, this is a void; prints all properties of the shape
void shapeDetails(Shape* shape){
    cout << "-------------------------------" << "\n";
    cout << "Shape type: " << shape->type() << "\n";
    cout << "Number of sides: " << shape->number_sides() << "\n";
    cout << "Shape area: " << shape->area() << "\n";
    cout << "Shape perimeter: " << shape->perimeter() << "\n";
    cout << "-------------------------------" << "\n";
}

// Define a class to sort shapes based on various atributes

int main(int, char**)
{
    // Set up shapes
    Rectangle rectangle1(3, 4);
    Square square1(5);
    Circle circle1(2);
    Triangle triangle1(2,4);

    vector<Shape*> ShapeList;
    ShapeList.push_back(&rectangle1);
    ShapeList.push_back(&square1);
    ShapeList.push_back(&circle1);
    ShapeList.push_back(&triangle1);


    for(vector<Shape*>::const_iterator it = ShapeList.begin(); 
            it != ShapeList.end(); it++){
// Test for type
        bool test_type;
        test_type = isShape((*it)->type(), "Square");
        if (test_type){
            cout << "Found shape of type: " << (*it)->type() << "\n";
            shapeDetails((*it));
        }
// Test for number of sides
        bool test_sides;
        test_sides = hasSides((*it)->number_sides(), 4);
        if (test_sides){
            cout << "Found shape with 4 sides: " << (*it)->type() << "\n";
            shapeDetails((*it));
        }
    }
    cout << "-------------------------------" << "\n";
    cout << "Sorting shapes by area   " << "\n";
    cout << "-------------------------------" << "\n";
    sortArea(ShapeList);

    cout << "-------------------------------" << "\n";
    cout << "Sorting shapes by perimeter   " << "\n";
    cout << "-------------------------------" << "\n";
    sortPerim(ShapeList);

}

