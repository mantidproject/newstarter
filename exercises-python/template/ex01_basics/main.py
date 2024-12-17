#!/usr/bin/env python3
import unittest
from collections import Counter


#class Tester(unittest.TestCase):
    #def test_on_import_gui_flag_is_set_to_false_here(self):
        #self.assertEqual(False, mantid.__gui__)

class WordCounter:
	def __init__(self):
		self.lines = None
		self.words = None
		self.sorted_words = None

	def request_file(self):
		return input("Enter file path: ")

	def read_file(self):
		no_file = True
		while no_file == True:
			try:
				with open(self.request_file(), 'r') as f:
					self.lines = f.readlines()
				no_file = False
			except:
				print("Invalid File")

	def split_lines(self):
		self.words = [line.replace('-', ' ').split(' ') for line in self.lines]

	def remove_punctuation(self, word):
		return ''.join([letter.lower() for letter in word if letter.isalpha()])

	def process_words(self):
		nested_words = [[self.remove_punctuation(word) for word in line if len(self.remove_punctuation(word)) > 4] for line in self.words]
		self.words = self.flatten_nested_list(nested_words)

	def flatten_nested_list(self, outer_list):
		return [item for inner_list in outer_list for item in inner_list]

	def count_and_sort(self):
		counter = Counter(self.words)
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


def main():
	word_counter = WordCounter()
	word_counter.run_all()


if __name__ == "__main__":
	main()
