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
    private:
        string shape_type;
        unsigned int num_sides;

    // Methods
    public:
		Shape(const string &type, int sides) {
			shape_type = type;
			num_sides = sides;
		}

        // Methods to be overridden
        virtual double perimeter() = 0;
        virtual double area() = 0;

        // Methods for info
        void print_type() const {
            cout << "Shape type is: " << get_shape_type() << endl;
        }

        virtual void print_num_sides() const {
            cout << "Number of sides is: " << get_num_sides() << endl;
        }

		// Getters
		string get_shape_type() const {
			return shape_type;
		}

		int get_num_sides() const {
			return num_sides;
		}

		// Destructor
		virtual ~Shape() {}

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
        Square(double width) : Shape("Square", 4) {
            side_length = width;
        }

        // Calculates and returns the perimeter
        double perimeter() override {
            return 4*side_length;
        }

        // Calculates and returns the area
        double area() override {
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
        Rectangle(double side1, double side2) : Shape("Rectangle", 4) {
            side1_len = side1;
            side2_len = side2;
        }

        // Calculates and returns the perimeter
        double perimeter() override {
            return (2*side1_len + 2*side2_len);
        }

        // Calculates and returns the area
        double area() override {
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
        Circle(double radius) : Shape("Circle", 0)  {
            radius_size = radius;
        }

        // Calculates and returns the perimeter
        double perimeter() override {
            return (2*M_PI*radius_size);
        }

        // Calculates and returns the area
        double area() override {
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
		Triangle(double height, double base) : Shape("Triangle", 3) {
            height_len = height;
            base_len = base;
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
                if(((*it)->get_shape_type()).compare(name) == 0) {
                    cout << (*it)->get_shape_type() << endl;
                }
            }
        }

        // Method to print shapes of chosen number of sides
        void print_shapes_matching_num_sides(vector<Shape*> shapes, int num_sides) {
            for(vector<Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); ++it) {
                if(((*it)->get_num_sides()) == num_sides) {
                    cout << (*it)->get_shape_type() << endl;
                }
            }
        }

        // Print the shapes by area descending
        void print_area_des(vector<Shape*> shapes) {
            vector<Shape*> sorted_areas = shapes;
            sort(sorted_areas.begin(), sorted_areas.end(), ShapeSorter::compare_area);

            for(vector<Shape*>::iterator it = sorted_areas.begin(); it != sorted_areas.end(); ++it) {
                cout << (*it)->get_shape_type() << "\t\t" << (*it)->area() << endl;
            }
        }

        // Print the shapes by perimeter descending
        void print_per_des(vector<Shape*> shapes) {
            vector<Shape*> sorted_per = shapes;
            sort(sorted_per.begin(), sorted_per.end(), ShapeSorter::compare_perimeter);

            for(vector<Shape*>::iterator it = sorted_per.begin(); it != sorted_per.end(); ++it) {
                cout << (*it)->get_shape_type() << "\t\t" <<(*it)->perimeter() << endl;
            }
        }
};


/**
 *  Main method
**/
int main() {
	// Shapes
	Square square(5);
	Rectangle rectangle(5, 10);
	Circle circle(5);
	Triangle triangle(10, 5);

    // Add shapes into a vector
    vector<Shape*> shapes;
    shapes.push_back(&square);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);
    shapes.push_back(&triangle);
	
	// Loop through each shape
	for each (Shape *shape in shapes) {
		shape->print_type();
		shape->print_num_sides();
		cout << "Area: " << shape->area() << endl;
		cout << "Perimeter: " << shape->perimeter() << endl;
		cout << endl;
	}


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