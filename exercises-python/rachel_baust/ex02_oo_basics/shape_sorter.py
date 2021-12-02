#!/usr/bin/env python3

class ShapeSorter:
    @staticmethod
    def print_shape(shape):
        print('Shape: {0}, Area: {1}, Perimeter: {2}'.format(shape.type, shape.area(), shape.perimeter()))

    @classmethod
    def print_by_type(cls, shape_type, shape_list):
        for shape in shape_list:
            if shape.type.casefold() == shape_type.casefold():
                cls.print_shape(shape)

    @classmethod
    def print_by_num_sides(cls, num_sides, shape_list):
        for shape in shape_list:
            if shape.num_sides == num_sides:
                cls.print_shape(shape)

    @classmethod
    def print_by_area_desc(cls, shape_list):
        for sorted_shape in sorted(shape_list, key=lambda shape: shape.area(), reverse=True):
            cls.print_shape(sorted_shape)

    @classmethod
    def print_by_perimeter_desc(cls, shape_list):
        for sorted_shape in sorted(shape_list, key=lambda shape: shape.perimeter(), reverse=True):
            cls.print_shape(sorted_shape)

