// Imports
#include <iostream>
#include <string>

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
 *  Main method
**/
int main(int, char **) {
    // Create a square
    Square square(5);
    
    // Print details of square
    square.print_type();
    cout << "Area: " << square.area() << endl;

    return 0;
}