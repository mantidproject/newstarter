#!/usr/bin/env python3

class ShapeSorter:
    @staticmethod
    def print_type_match( shape_type, shape_list):
        for shape in shape_list:
            if shape.type.casefold() == shape_type.casefold():
                shape.print_shape()

    @staticmethod
    def print_num_sides_match(num_sides, shape_list):
        for shape in shape_list:
            if shape.num_sides == num_sides:
                shape.print_shape()

    @staticmethod
    def print_by_area_desc(shape_list):
        for sorted_shape in sorted(shape_list, key=lambda shape: shape.area(), reverse=True):
            sorted_shape.print_shape()

    @staticmethod
    def print_by_perimeter_desc(shape_list):
        for sorted_shape in sorted(shape_list, key=lambda shape: shape.perimeter(), reverse=True):
            sorted_shape.print_shape()

