from Shapes import *


class ShapeSorter:
    def __init__(self, shapes: list[Shape]):
        self.shapes = shapes

    def of_type(self, shape_type: type):
        matching_shapes = [s for s in self.shapes if isinstance(s, shape_type)]
        if len(matching_shapes) == 0:
            print("No shapes of type " + str(shape_type))
            return
        for shape in matching_shapes:
            print(shape.to_string())

    def with_sides(self, number_sides: int):
        matching_shapes = [s for s in self.shapes if s.sides == number_sides]
        if len(matching_shapes) == 0:
            print("No shapes with " + str(number_sides) + " sides")
            return
        for shape in matching_shapes:
            print(shape.to_string())

    def area_descending(self):
        sorted_by_area = sorted(self.shapes, key=lambda s: s.area, reverse=True)
        for shape in sorted_by_area:
            print(shape.to_string())

    def perimeter_descending(self):
        sorted_by_perimeter = sorted(self.shapes, key=lambda s: s.perimeter, reverse=True)
        for shape in sorted_by_perimeter:
            print(shape.to_string())
