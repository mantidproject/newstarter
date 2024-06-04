#!/usr/bin/env python3
from abc import abstractmethod, ABC
from math import sqrt, pow, pi


class ShapeClass:
    def __int__(self, shape_type, number_of_sides):
        self.shape_type = shape_type
        self.number_of_sides = number_of_sides

    def get_number_of_sides(self):
        return self.number_of_sides

    def get_type(self):
        return self.shape_type

    @abstractmethod
    def perimeter(self):
        pass

    @abstractmethod
    def area(self):
        pass


class Triangle(ShapeClass, ABC):

    # overriding abstract method
    def __init__(self, base, height):
        super().__int__(shape_type="Triangle", number_of_sides=3)
        self.base = base
        self.height = height

    def perimeter(self):
        return self.base + (2 * (sqrt(pow(self.height, 2) + (pow(self.base, 2) / 4))))

    def area(self):
        return 0.5 * self.base * self.height


class Circle(ShapeClass, ABC):

    # overriding abstract method
    def __init__(self, radius):
        super().__int__(shape_type="`Circle`")
        self.radius = radius

    def perimeter(self):
        return 2 * pi * self.radius

    def area(self):
        return pi * pow(self.radius, 2)


class Square(ShapeClass, ABC):

    def __init__(self, side1):
        super().__int__(shape_type="Square", number_of_sides=4)
        self.side1 = side1

    def perimeter(self):
        return 4 * self.side1

    def area(self):
        return pow(self.side1, 2)


class Rectangle(ShapeClass, ABC):

    # overriding abstract method
    def __init__(self, side1, side2):
        super().__int__(shape_type="Rectangle", number_of_sides=4)
        self.side1 = side1
        self.side2 = side2

    def perimeter(self):
        return 2 * (self.side1 + self.side2)

    def area(self):
        return self.side1 * self.side2


class ShapeSorter:
    def __init__(self, container = []):
        self.container = container

    def match_chosen_type(self, chosen_type):
        return [item for item in self.container if item.get_type().lower() == chosen_type.lower()]

    def match_chosen_number_of_sides(self, sides):
        return [item for item in self.container if item.get_number_of_sides() == sides]

    def area_descending(self):
        return sorted(self.container, key=lambda shape: shape.area(), reverse=True)

    def perimeter_descending(self):
        return sorted(self.container, key=lambda shape: shape.perimeter(), reverse=True)


def main():
    shapeSorter = ShapeSorter()
    container = [Triangle(7, 2), Square(2), Rectangle(4, 12)]
    shapeSorter.container = container
    print([item.get_type() for item in shapeSorter.match_chosen_type("Triangle")])
    print([item.get_type() for item in shapeSorter.match_chosen_number_of_sides(4)])
    print([item.get_type() for item in shapeSorter.area_descending()])
    print([item.get_type() for item in shapeSorter.perimeter_descending()])
    pass


if __name__ == "__main__":
    main()
