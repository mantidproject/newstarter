#!/usr/bin/env python3
import unittest
from collections import Counter

class WordCounter:
	def __init__(self):
		self.lines = None
		self.words = None
		self.sorted_words = None

	def request_file(self):
		# get user defined input
		return input("Enter file path: ")

	def read_file(self):
		# assert there is no file and then keep requesting inputs until one that can be read is given
		no_file = True

		# I prefer the explicit no_file == True but pyCharm was complaining so here we are
		while no_file:
			try:
				with open(self.request_file(), 'r') as f:
					self.lines = f.readlines()
				no_file = False
			except OSError:
				print("Invalid File")

	def split_lines(self):
		# replace hyphens with spaces and then split the line at each space
		self.words = [line.replace('-', ' ').split(' ') for line in self.lines]

	def remove_punctuation(self, word):
		# list comprehension of characters that are alphabetic - then concatenated back into a string
		return ''.join([letter.lower() for letter in word if letter.isalpha()])

	def process_words(self):
		# iterate over each word in each line, remove the punctuation and check the length
		# returns a nested list: [[first_word_in_line_one, second_word_in_line_one],[first_word_in_line_two, second_word_in_line_two],...]
		nested_words = [[self.remove_punctuation(word) for word in line if len(self.remove_punctuation(word)) > 4] for line in self.words]

		# flatten into just a single list of all the words
		self.words = self.flatten_nested_list(nested_words)

	def flatten_nested_list(self, outer_list):
		# flattens a list
		return [item for inner_list in outer_list for item in inner_list]

	def count_and_sort(self):
		# Counter makes a dictionary counting occurance of each iterable (the list of all words in this case)
		counter = Counter(self.words)

		# Sort counter dict by the negative of the occurance to sort in descending
		self.sorted_words = dict(sorted(counter.items(), key=lambda item: -item[1]))

	def output_results(self):
		print("Word           Usage")
		for k,v in self.sorted_words.items():
			print(k + " "*(15 - len(k)) + str(v))

	def run_all(self):
		self.read_file()
		self.split_lines()
		self.process_words()
		self.count_and_sort()
		self.output_results()


class Tester(unittest.TestCase):

	def test_split_lines(self):
		# setup input
		test_word_counter = WordCounter()
		test_word_counter.lines = ['test line one', 'test-line two']
		# expected outcome
		expected_output = [['test', 'line', 'one'], ['test', 'line', 'two']]

		# apply the function
		test_word_counter.split_lines()

		self.assertEqual(expected_output, test_word_counter.words)

	def test_remove_punctuation(self):
		# setup input
		test_word_counter = WordCounter()
		inputs = ['A!', 'set,', 'of?', 'test\"', 'inputs.']
		# expected outcome
		expected_output = ['a', 'set', 'of', 'test', 'inputs']

		output = [test_word_counter.remove_punctuation(w) for w in inputs]

		self.assertEqual(expected_output, output)

	def test_process_words(self):
		# setup input
		test_word_counter = WordCounter()
		test_word_counter.words =  [['tests', 'line', 'one'], ['tests', 'line', 'two', 'after']]
		# expected outcome
		expected_output = ['tests', 'tests', 'after']

		test_word_counter.process_words()

		self.assertEqual(expected_output, test_word_counter.words)

def main():
	#word_counter = WordCounter()
	#word_counter.run_all()

	Tester()


if __name__ == "__main__":
	main()
