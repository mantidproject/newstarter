#!/usr/bin/env python3
from math import pi
import unittest

class Rectangle:
	def __init__(self, s1, s2, name = 'rectangle'):
		self.shape = "Rectangle"
		self.num_sides = 4
		self.name = name
		self.side1 = s1
		self.side2 = s2
		self.calculate_area()
		self.calculate_perimeter()

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
		self.calculate_area()
		self.calculate_perimeter()

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
		self.calculate_area()
		self.calculate_perimeter()

	def calculate_area(self):
		self.area = 0.5*self.base*self.height

	def calculate_perimeter(self):
		self.perimeter = self.base + 2*((self.height**2 + (self.base**2)/4)**0.5)

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
			print(f'Shape: {shape.name}, Perimeter: {shape.perimeter}')

class Tester(unittest.TestCase):

	def test_rectangle_area(self):
		# setup input
		sides1s = [ 1, 2.3, 3 ]
		sides2s = [ 1, 1, 2.5 ]
		# expected outcome
		expected_output = [ 1, 2.3, 7.5 ]

		# apply the function
		output = [round(Rectangle(sides1s[i], sides2s[i]).area,4) for i in range(len(sides1s))]

		self.assertEqual(expected_output, output)

	def test_rectangle_perimeter(self):
		# setup input
		sides1s = [ 1, 2.3, 3 ]
		sides2s = [ 1, 1, 2.5 ]
		# expected outcome
		expected_output = [ 4, 6.6, 11 ]

		# apply the function
		output = [round(Rectangle(sides1s[i], sides2s[i]).perimeter, 4) for i in range(len(sides1s))]

		self.assertEqual(expected_output, output)


	def test_square_perimeter(self):
		# setup input
		sides1s = [ 1, 2.3, 3 ]
		# expected outcome
		expected_output = [ 4, 9.2, 12 ]

		# apply the function
		output = [round(Square(sides1s[i]).perimeter, 4) for i in range(len(sides1s))]

		self.assertEqual(expected_output, output)

	def test_square_area(self):
		# setup input
		sides1s = [ 1, 2.3, 3 ]
		# expected outcome
		expected_output = [  1, 5.29, 9  ]

		# apply the function
		output = [round(Square(sides1s[i]).area, 4) for i in range(len(sides1s))]

		self.assertEqual(expected_output, output)

	def test_circle_perimeter(self):
		# setup input
		radii = [ 1, 2.3, 3 ]
		# expected outcome
		expected_output = [ 6.2832, 14.4513, 18.8496 ]

		# apply the function
		output = [round(Circle(radii[i]).perimeter, 4) for i in range(len(radii))]

		self.assertEqual(expected_output, output)

	def test_circle_area(self):
		# setup input
		radii = [ 1, 2.3, 3 ]
		# expected outcome
		expected_output = [  3.1416, 16.6190, 28.2743 ]

		# apply the function
		output = [round(Circle(radii[i]).area, 4) for i in range(len(radii))]

		self.assertEqual(expected_output, output)


	def test_triangle_perimeter(self):
		# setup input
		bases = [ 1, 2.3, 3 ]
		heights = [ 1, 1, 2.5 ]
		# expected outcome
		expected_output = [ 3.236, 5.348, 8.831 ]

		# apply the function
		output = [round(Triangle(bases[i], heights[i]).perimeter, 3) for i in range(len(bases))]

		self.assertEqual(expected_output, output)

	def test_triangle_area(self):
		# setup input
		bases = [ 1, 2.3, 3 ]
		heights = [ 1, 1, 2.5 ]
		# expected outcome
		expected_output = [  0.5, 1.15, 3.75 ]

		# apply the function
		output = [round(Triangle(bases[i], heights[i]).area, 4) for i in range(len(bases))]

		self.assertEqual(expected_output, output)


def main():
	shapes = [Rectangle(1,2, 'recky'),
			  Square(1, 'squaro'),
			  Square(3, 'squara'),
			  Circle(1.3, 'mr circ'),
			  Triangle(2.9, 2.3, 'points')]

	shape_sorter = ShapeSorter(shapes)

	shape_sorter.print_shape_by_type('Square')
	shape_sorter.print_shape_by_sides(4)
	shape_sorter.print_shape_by_area()
	shape_sorter.print_shape_by_perimeter()


if __name__ == "__main__":
	#Tester()

	main()
