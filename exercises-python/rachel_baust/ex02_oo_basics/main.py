#!/usr/bin/env python3
from math import pi, pow as sq, sqrt
from shape_sorter import ShapeSorter
from abc import ABC, abstractmethod


def main():
    shape_list = [Square(4), Rectangle(4, 2), Circle(5), Triangle(3, 5), Square(3)]
    print_header('Same Type')
    ShapeSorter.print_type_match('Square', shape_list)
    print_header('Same number of sides')
    ShapeSorter.print_num_sides_match(4, shape_list)
    print_header('Ordered by area')
    ShapeSorter.print_by_area_desc(shape_list)
    print_header('Ordered by perimeter')
    ShapeSorter.print_by_perimeter_desc(shape_list)


def print_header(text):
    print('\n{0}\n--------------------'.format(text))


class Shape(ABC):

    def __init__(self, shape_type, num_sides):
        self.type = shape_type
        self.num_sides = num_sides

    @abstractmethod
    def area(self):
        """
        Calculates the area of the shape
        :return: value for the area of the shape
        """
        pass

    @abstractmethod
    def perimeter(self):
        """
        Calculates the perimeter of the shape
        :return: value for the perimeter of the shape
        """
        pass

    def print_shape(self):
        print(f'Shape: {self.type}, Area: {self.area()}, Perimeter: {self.perimeter()}')


class Square(Shape):

    def __init__(self, side1):
        super().__init__('Square', 4)
        self._side1 = side1

    def area(self):
        return sq(self._side1, 2)

    def perimeter(self):
        return self._side1 * 4


class Rectangle(Shape):

    def __init__(self, side1, side2):
        super().__init__('Rectangle', 4)
        self._side1 = side1
        self._side2 = side2

    def area(self):
        return self._side1 * self._side2

    def perimeter(self):
        return (self._side1 * 2) + (self._side2 * 2)


class Circle(Shape):

    def __init__(self, radius):
        super().__init__('Circle', 0)
        self._radius = radius

    def area(self):
        return pi * sq(self._radius, 2)

    def perimeter(self):
        return 2 * pi * self._radius


class Triangle(Shape):

    def __init__(self, height, base):
        super().__init__('Triangle', 3)
        self._height = height
        self._base = base

    def area(self):
        return (self._base * self._height) / 2

    def perimeter(self):
        return self._base + 2 * sqrt(sq(self._height, 2) + sq(self._base, 2)/4)


if __name__ == "__main__":
    main()
