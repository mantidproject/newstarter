import unittest
from main import *


class MyTestCase(unittest.TestCase):
    def test_shape_creation(self):
        shape = ShapeClass()
        shape.shape_type = "square"
        shape.number_of_sides = 4
        self.assertEqual(shape.shape_type, "square")
        self.assertEqual(shape.number_of_sides, 4)

    def test_triangle_creation(self):
        triangle = Triangle(2, 3)
        self.assertEqual(triangle.get_type(), "Triangle")
        self.assertEqual(triangle.get_number_of_sides(), 3)

    def test_triangle_area(self):
        triangle = Triangle(2, 3)
        self.assertEqual(triangle.area(), 3)

    def test_triangle_perimeter(self):
        triangle = Triangle(2, 3)
        self.assertEqual(triangle.perimeter(), 8)

    def test_shape_sorter_initialization(self):
        shapeSorter = ShapeSorter([])
        self.assertEqual(len(shapeSorter.container), 0)

    def test_shape_sorter_can_hold_shapes(self):
        container = [Triangle(2, 3), Square(2)]
        shapeSorter = ShapeSorter(container)
        self.assertEqual(len(shapeSorter.container), 2)

    def test_that_shape_sorter_return_shape_that_match_chosen_type(self):
        container = [Triangle(2, 3), Square(2), Triangle(4, 5)]
        shapeSorter = ShapeSorter(container)
        shapes = shapeSorter.match_chosen_type("triangle")
        self.assertEqual(len(shapes), 2)
        self.assertEqual(shapes[0].get_type(), "Triangle")
        self.assertTrue(shapes[0].get_number_of_sides() == 3)

    def test_that_shape_sorter_return_shape_that_match_chosen_number_of_sides(self):
        container = [Triangle(2, 3), Square(2), Rectangle(4, 12)]
        shapeSorter = ShapeSorter(container)
        shapes = shapeSorter.match_chosen_number_of_sides(4)
        self.assertEqual(len(shapes), 2)
        self.assertEqual(shapes[0].get_type(), "Square")
        self.assertTrue(shapes[0].get_number_of_sides() == 4)
        self.assertEqual(shapes[1].get_type(), "Rectangle")
        self.assertTrue(shapes[1].get_number_of_sides() == 4)

    def test_that_shape_sorter_return_shapes_in_order_of_area_descending(self):
        container = [Triangle(2, 3), Square(2), Rectangle(4, 12)]
        shapeSorter = ShapeSorter(container)
        shapes = shapeSorter.area_descending()
        self.assertEqual(len(shapes), 3)
        self.assertEqual(shapes[0].get_type(), "Rectangle")
        self.assertEqual(shapes[1].get_type(), "Square")
        self.assertEqual(shapes[2].get_type(), "Triangle")

    def test_that_shape_sorter_return_shapes_in_order_of_perimeter_descending(self):
        container = [Triangle(7, 2), Square(2), Rectangle(4, 12)]
        print(Triangle(7, 2).perimeter())
        print(Square(2).perimeter())
        print(Rectangle(4, 12).perimeter())
        shapeSorter = ShapeSorter(container)
        shapes = shapeSorter.perimeter_descending()
        self.assertEqual(len(shapes), 3)
        self.assertEqual(shapes[0].get_type(), "Rectangle")
        self.assertEqual(shapes[1].get_type(), "Triangle")
        self.assertEqual(shapes[2].get_type(), "Square")


if __name__ == '__main__':
    unittest.main()
