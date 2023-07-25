import math


class Shape:
    _type_name = "Shape"

    def __init__(self, number_of_sides: int, total_area: float, perimeter_length: float):
        self.sides = number_of_sides
        self.area = total_area
        self.perimeter = perimeter_length

    def to_string(self) -> str:
        return self._type_name + " " + str(self.sides) + " sides, " + str(self.perimeter) + " perimeter, " \
            + str(self.area) + " area"


class Rectangle(Shape):
    _type_name = "Rectangle"

    def __init__(self, side_length: float, other_side_length: float):
        my_area = side_length * other_side_length
        my_perimeter = 2 * side_length + 2 * other_side_length
        Shape.__init__(self, number_of_sides=4, total_area=my_area, perimeter_length=my_perimeter)


class Square(Rectangle):
    _type_name = "Square"

    def __init__(self, every_side_length: float):
        Rectangle.__init__(self, side_length=every_side_length, other_side_length=every_side_length)


class Circle(Shape):
    _type_name = "Circle"

    def __init__(self, radius: float):
        my_area = math.pi * radius**2
        my_perimeter = 2 * math.pi * radius
        Shape.__init__(self, number_of_sides=1, total_area=my_area, perimeter_length=my_perimeter)


class Triangle(Shape):
    _type_name = "Triangle"

    def __init__(self, height: float, base: float):
        my_area = 0.5 * base * height
        my_perimeter = base + 2*math.sqrt(height**2 + base**2 / 4)
        Shape.__init__(self, number_of_sides=3, total_area=my_area, perimeter_length=my_perimeter)