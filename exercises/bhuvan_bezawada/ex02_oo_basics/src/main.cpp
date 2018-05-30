// Imports
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
#include <algorithm>

// Namespace to use
using namespace std;


/**
 *  Base class
**/
class Shape {
    // Instance variables
    public:
        string shape_type;
        int num_sides;

    // Methods to implement
    public:
        virtual void print_type() = 0;
        virtual void print_num_sides() = 0;
        virtual double perimeter() = 0;
        virtual double area() = 0;
};


/**
 *  Square class
**/
class Square : public Shape {

    // Own side length
    private:
        double side_length;

    // Method implementations
    public:
        // Constructor 
        Square(int side1) {
            side_length = side1;
            shape_type = "Square";
            num_sides = 4;
        }

        // Let's user know what type it is
        void print_type() {
            cout << "Shape type is: " << shape_type << endl;
        }

        // Prints out number of sides
        void print_num_sides() {
            cout << "Number of sides is: " << num_sides << endl;
        }

        // Calculates and returns the perimeter
        double perimeter() {
            return 4*side_length;
        }

        // Calculates and returns the area
        double area() {
            return side_length*side_length;
        }

        // Prints out the length of its side
        void print_side_length() {
            cout << "Side length is: " << side_length << endl;
        }
};


/**
 *  Rectangle class
**/
class Rectangle : public Shape {

    // Own side lengths
    private:
        double side1_len;
        double side2_len;

    // Method implementations
    public:
        // Constructor 
        Rectangle(double side1, double side2) {
            side1_len = side1;
            side2_len = side2;
            shape_type = "Rectangle";
            num_sides = 4;
        }

        // Let's user know what type it is
        void print_type() {
            cout << "Shape type is: " << shape_type << endl;
        }

        // Prints out number of sides
        void print_num_sides() {
            cout << "Number of sides is: " << num_sides << endl;
        }

        // Calculates and returns the perimeter
        double perimeter() {
            return (2*side1_len + 2*side2_len);
        }

        // Calculates and returns the area
        double area() {
            return side1_len*side2_len;
        }

        // Prints out the length of its side
        void print_side_lengths() {
            cout << "Side 1 length is: " << side1_len << endl;
            cout << "Side 2 length is: " << side2_len << endl;
        }
};


/**
 *  Circle class
**/
class Circle : public Shape {

    // Own radius
    private:
        double radius_size;

    // Method implementations
    public:
        // Constructor 
        Circle(double radius) {
            radius_size = radius;
            shape_type = "Circle";
            num_sides = 0;
        }

        // Let's user know what type it is
        void print_type() {
            cout << "Shape type is: " << shape_type << endl;
        }

        // Prints out number of sides
        void print_num_sides() {
            cout << "Number of sides is: " << num_sides << endl;
        }

        // Calculates and returns the perimeter
        double perimeter() {
            return (2*M_PI*radius_size);
        }

        // Calculates and returns the area
        double area() {
            return (M_PI*radius_size*radius_size);
        }

        // Prints out the length of its radius
        void print_radius_length() {
            cout << "Radius length is: " << radius_size << endl;
        }
};


/**
 *  Triangle class
**/
class Triangle : public Shape {

    // Own height and base
    private:
        double height_len;
        double base_len;

    // Method implementations
    public:
        // Constructor 
        Triangle(double height, double base) {
            height_len = height;
            base_len = base;
            shape_type = "Triangle";
            num_sides = 3;
        }

        // Let's user know what type it is
        void print_type() {
            cout << "Shape type is: " << shape_type << endl;
        }

        // Prints out number of sides
        void print_num_sides() {
            cout << "Number of sides is: " << num_sides << endl;
        }

        // Calculates and returns the perimeter
        double perimeter() {
            return (base_len + 2 * sqrt(height_len*height_len + (base_len*base_len)/4));
        }

        // Calculates and returns the area
        double area() {
            return (0.5*base_len*height_len);
        }

        // Prints out the length of its radius
        void print_side_lengths() {
            cout << "Height length is: " << height_len << endl;
            cout << "Base length is: " << base_len << endl;
        }
};



/**
 *  ShapeSorter class
**/
class ShapeSorter {

    /**
     * Comparators for sort()
     * 
     * http://www.cplusplus.com/reference/algorithm/sort/ 
    **/
    static bool compare_area(Shape* shape1, Shape* shape2) {
        return shape1->area() > shape2->area();
    }

    static bool compare_perimeter(Shape* shape1, Shape* shape2) {
        return shape1->perimeter() > shape2->perimeter();
    }


    public:
        // Method to print matching given type
        void print_matching_type(vector<Shape*> shapes, string name) {
            for(vector<Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); ++it) {
                if(((*it)->shape_type).compare(name) == 0) {
                    cout << (*it)->shape_type << endl;
                }
            }
        }

        // Method to print shapes of chosen number of sides
        void print_shapes_matching_num_sides(vector<Shape*> shapes, int num_sides) {
            for(vector<Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); ++it) {
                if(((*it)->num_sides) == num_sides) {
                    cout << (*it)->shape_type << endl;
                }
            }
        }


        void print_area_des(vector<Shape*> shapes) {
            vector<Shape*> sorted_areas = shapes;
            sort(sorted_areas.begin(), sorted_areas.end(), ShapeSorter::compare_area);

            for(vector<Shape*>::iterator it = sorted_areas.begin(); it != sorted_areas.end(); ++it) {
                cout << (*it)->shape_type << (*it)->area() << endl;
            }
        }


        void print_per_des(vector<Shape*> shapes) {
            vector<Shape*> sorted_per = shapes;
            sort(sorted_per.begin(), sorted_per.end(), ShapeSorter::compare_perimeter);

            for(vector<Shape*>::iterator it = sorted_per.begin(); it != sorted_per.end(); ++it) {
                cout << (*it)->shape_type << (*it)->perimeter() << endl;
            }
        }
};


/**
 *  Main method
**/
int main(int, char **) {
    // Create a square
    Square square(5);
    // Print details of square
    square.print_type();
    cout << "Area: " << square.area() << endl;


    // Create a rectangle
    Rectangle rectangle(5, 10);
    // Print details of rectangle
    rectangle.print_type();
    cout << "Area: " << rectangle.area() << endl;


    // Create a circle
    Circle circle(5);
    // Print details of circle
    circle.print_type();
    cout << "Area: " << circle.area() << endl;


    // Create a triangle
    Triangle triangle(10, 5);
    // Print details of triangle
    triangle.print_type();
    cout << "Area: " << triangle.area() << endl;


    // Add shapes into a vector
    vector<Shape*> shapes;
    shapes.push_back(&square);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);
    shapes.push_back(&triangle);

    // Print chosen types
    cout << "\n\nShape sorting section\n\n" << endl;
    ShapeSorter ss;
    
    ss.print_matching_type(shapes, "Square");
    cout << endl;
    ss.print_shapes_matching_num_sides(shapes, 4);
    cout << endl;
    ss.print_area_des(shapes);
    cout << endl;
    ss.print_per_des(shapes);
    cout << endl;

    return 0;
}