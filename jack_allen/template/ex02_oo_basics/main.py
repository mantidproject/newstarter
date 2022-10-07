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


class Square(Shape):
    """
    Square class
    """
    def __init__(self, side: int):
        super().__init__("Square", 4)
        self.side = side

    @property
    def get_area(self) -> int:
        """
        Calculate area of square

        @return: area of square
        """
        return self.side * self.side

    @property
    def get_perimeter(self) -> int:
        """
        Calculate perimeter of square

        @return: perimeter of square
        """
        return self.side * self.sides


class Rectangle(Shape):
    """
    Rectangle class
    """
    def __init__(self, side1: int, side2: int):
        super().__init__("Rectangle", 4)
        self.side1 = side1
        self.side2 = side2

    @property
    def get_area(self) -> int:
        """
        Calculate area of rectangle

        @return: area of rectangle
        """
        return self.side1 * self.side2

    @property
    def get_perimeter(self):
        """
        Calculate perimeter of rectangle

        @return: perimeter of rectangle
        """
        return (self.side1 * 2) + (self.side2 * 2)


class Circle(Shape):
    """
    Circle class
    """
    def __init__(self, radius: int):
        super().__init__("Circle", 0)
        self.radius = radius

    @property
    def get_area(self) -> float:
        """
        Calculate area of circle

        @return: area of circle
        """
        return self.radius * self.radius * 3.14

    @property
    def get_perimeter(self):
        """
        Calculate perimeter of circle

        @return: perimeter of circle
        """
        return 2 * 3.14 * self.radius



class Triangle(Shape):
    """
    Triangle class
    """
    def __init__(self, height: int, base: int):
        super().__init__("Triangle", 3)
        self.height = height
        self.base = base

    @property
    def get_area(self) -> float:
        """
        Calculate area of triangle

        @return: area of triangle
        """
        return (self.base * self.height) / 2

    @property
    def get_perimeter(self) -> float:
        """
        Calculate perimeter of triangle

        @return: perimeter of triangle
        """
        return self.base + 2 * (self.height ** 2 + (self.base ** 2 / 4)) ** 0.5


class ShapeSorter:
    """
    Class to sort shapes
    """
    def __init__(self, shapes: list):
        self.shapes = shapes

    def print_shapes_by_type(self, type: str) -> None:
        """
        Print shapes by type

        @param type: type of shape
        """
        pass

    def print_shapes_by_sides(self, sides: int) -> None:
        """
        Print shapes by number of sides

        @param sides: number of sides
        """
        pass

    def print_shapes_by_area(self) -> None:
        """
        Print shapes by area
        """
        pass
    def print_shapes_by_perimeter(self) -> None:
        """
        Print shapes by perimeter
        """
        pass

def main():
    """
    Main method to run the program
    """
   # Create a list of shapes
    shapes = [Square(5), Rectangle(5, 10), Circle(5), Triangle(5, 10)]

if __name__ == "__main__":
    main()
