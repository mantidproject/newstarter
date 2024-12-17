#!/usr/bin/env python3
from math import pi

class Rectangle:
	def __init__(self, s1, s2, name = 'rectangle'):
		self.shape = "Rectangle"
		self.num_sides = 4
		self.name = name
		self.side1 = s1
		self.side2 = s2
	def calculate_area(self):
		self.area = self.side1 * self.side2
	def calculate_perimeter(self):
		self.perimeter = 2*(self.side1 + self.side2)

class Square(Rectangle):
	def __init__(self, s1, name = 'square'):
		super().__init__(s1, s1, name)
		self.shape = "Square"

class Circle:
	def __init__(self, radius, name = 'circle'):
		self.shape = "Circle"
		self.num_sides = 1
		self.radius = radius
		self.name = name
	def calculate_area(self):
		self.area = pi*self.radius**2
	def calculate_perimeter(self):
		self.perimeter = 2*pi*self.radius

class Triangle:
	def __init__(self, base, height, name = 'triangle'):
		self.shape = "Triangle"
		self.num_sides = 3
		self.base = base
		self.height = height
		self.name = name
	def calculate_area(self):
		self.area = 0.5*self.base*self.height
	def calculate_perimeter(self):
		self.perimeter = self.base + 2*(self.height**2 + (self.base**2)/4)**0.5

class ShapeSorter:
	def __init__(self, shape_list):
		self.shape_list = shape_list
		self.sort_by_area()
		self.sort_by_perimeter()
	def sort_by_area(self):
		self.area_sorted = sorted(self.shape_list, key=lambda item: item.area, reverse= True)
	def sort_by_perimeter(self):
		self.perimeter_sorted = sorted(self.shape_list, key=lambda item: item.perimeter, reverse= True)
	def print_shape_by_type(self, target_shape):
		for shape in self.shape_list:
			if shape.shape == target_shape:
				print(shape.name)
	def print_shape_by_sides(self, n_sides):
		for shape in self.shape_list:
			if shape.num_sides == n_sides:
				print(shape.name)
	def print_shape_by_area(self):
		for shape in self.area_sorted:
			print(f'Shape: {shape.name}, Area: {shape.area}')
	def print_shape_by_perimeter(self):
		for shape in self.perimeter_sorted:
			print(f'Shape: {shape.name}, Area: {shape.perimeter}')


def main():
	pass


if __name__ == "__main__":
	main()
