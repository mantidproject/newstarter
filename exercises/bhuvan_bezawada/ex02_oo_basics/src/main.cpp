// Imports
#include <iostream>
#include <string>
#include <math.h>

// Namespace to use
using namespace std;


/**
 *  Base class
**/
class Shape {
    // Instance variables
    protected:
        string shape_type;
        int num_sides;

    // Methods
    public:
        void print_type();
        void print_num_sides();
        void perimeter();
        void area();
};


/**
 *  Square class
**/
class Square : protected Shape {

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
class Rectangle : protected Shape {

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
class Circle : protected Shape {

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
 *  Main method
**/
int main(int, char **) {
    // Create a square
    Square square(5);
    
    // Print details of square
    square.print_type();
    cout << "Area: " << square.area() << endl;


    // Create a square
    Rectangle rectangle(5, 10);
    
    // Print details of square
    rectangle.print_type();
    cout << "Area: " << rectangle.area() << endl;


    // Create a circle
    Circle circle(5);
    
    // Print details of square
    circle.print_type();
    cout << "Area: " << circle.area() << endl;

    return 0;
}