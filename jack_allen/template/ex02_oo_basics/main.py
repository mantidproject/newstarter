#!/usr/bin/env python3

"""
Solution for Exercise 2

Write a command line program that:

    1. Has classes to allow number of shapes to be defined: square (side1), rectangle(side1,
    side2), circle(radius), triangle(height, base).
        1. Each shape class should know it’s type (“Square”), how many sides it has.
        2. Each shape needs to be able to calculate it’s perimeter and area. For the triangle
        you can assume it is isosceles and the perimeter can be computed using
        p = b + 2\sqrt{h^2+(b^2/4)}, where b is the base and h is the height.

    2. Within the Main method create a variety of the shapes and put them in a list
        3. Create a class ShapeSorter which should contain four methods
        1. Print out the Shapes that match a chosen type
        2. Print out the Shapes that match a chosen number of sides
        3. Print out the Shapes in order of area descending
        4. Print out the Shapes in order of perimeter descending
"""

class Shape:
    """
    Superclass for all shapes to to be defined:
    square (side1),
    rectangle(side1, side2), circle(radius), triangle(height, base). assuming triangle is isosceles.
    """
    def __init__(self, type: str, sides: int):
        self.type = type
        self.sides = sides

    def __str__(self) -> str:
        return f"{self.type} with {self.sides} sides"

def main():
    """
    Main method to run the program
    """
    # Create a list of shapes
    shapes = []

if __name__ == "__main__":
    main()
