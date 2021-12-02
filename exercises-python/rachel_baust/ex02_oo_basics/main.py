#!/usr/bin/env python3
from math import pi, pow as sq, sqrt
import shape_sorter as ss


def main():
    shape_list = [Square(4), Rectangle(4, 2), Circle(5), Triangle(3, 5), Square(3)]
    print_header('Same Type')
    ss.ShapeSorter.print_by_type('Square', shape_list)
    print_header('Same number of sides')
    ss.ShapeSorter.print_by_num_sides(4, shape_list)
    print_header('Ordered by area')
    ss.ShapeSorter.print_by_area_desc(shape_list)
    print_header('Ordered by perimeter')
    ss.ShapeSorter.print_by_perimeter_desc(shape_list)


def print_header(text):
    print('\n{0}\n--------------------'.format(text))


class Square:
    type = 'Square'
    num_sides = 4

    def __init__(self, side1):
        self._side1 = side1

    def area(self):
        return sq(self._side1, 2)

    def perimeter(self):
        return self._side1 * self.num_sides


class Rectangle:
    type = 'Rectangle'
    num_sides = 4

    def __init__(self, side1, side2):
        self._side1 = side1
        self._side2 = side2

    def area(self):
        return self._side1 * self._side2

    def perimeter(self):
        return (self._side1 * 2) + (self._side2 * 2)


class Circle:
    type = 'Circle'
    num_sides = 0

    def __init__(self, radius):
        self._radius = radius

    def area(self):
        return pi * sq(self._radius, 2)

    def perimeter(self):
        return 2 * pi * self._radius


class Triangle:
    type = 'Triangle'
    num_sides = 3

    def __init__(self, height, base):
        self._height = height
        self._base = base

    def area(self):
        return (self._base * self._height) / 2

    def perimeter(self):
        return self._base + 2 * sqrt(sq(self._height, 2) + sq(self._base, 2)/4)


if __name__ == "__main__":
    main()
