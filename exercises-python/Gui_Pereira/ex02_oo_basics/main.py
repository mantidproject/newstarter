#!/usr/bin/env python3
import math

class Square:
    def __init__(self, side1):
        self.side1 = side1

        self.sides = 2
        self.area = self.side1**2

    def __str__(self):
        return f'Square {self.side1}'

class Rectangle:
    def __init__(self, side1, side2):
        self.side1 = side1
        self.side2 = side2

        self.sides = 2
        self.area = self.side1 * self.side2

    def __str__(self):
        return f'Rectangle {self.side1}x{self.side2}'

class Circle:
    def __init__(self, radius):
        self.radius = radius

        self.sides = 0
        self.area = self.radius**2 * math.pi 

    def __str__(self):
        return f'Circle {self.radius}'
     
class Triangle:
    def __init__(self, base, height):
        self.base = base
        self.height = height

        self.sides = 3
        self.area = self.base * self.height / 2 

    def __str__(self):
        return f'Triangle {self.base}x{self.height}'

class ShapeSorter:

    def __init__(self, shapes):
        self.shapes = shapes

    def sort_by_area(self):
        shapes_list = sorted(self.shapes, key=lambda x : - x.area)
        print('\nSorted shapes by area (descending):\n')
        for s in shapes_list: print(s)

    # For perimeter function, would use the same reasoning as for area

    def print_matching_shapes(self, shape_name):
        shapes_list  = [s for s in self.shapes if s.__class__.__name__==shape_name]
        print(f'\nMatching shapes for {shape_name}:\n')
        for s in shapes_list: print(s)

    # For matching shapes by number of sides, would use the same reasoning as for matching types


def main():
    test_shapes =  [Square(2), Square(3), Rectangle(4, 3), Rectangle(1, 3), Circle(3), Triangle(1, 2), Triangle(1, 5), Triangle(2, 2)]
    SS = ShapeSorter(test_shapes)
    SS.sort_by_area()
    SS.print_matching_shapes('Triangle')


if __name__ == "__main__":
	main()
