import unittest
from unittest.mock import mock_open, patch
from main import *


class WordCountTest(unittest.TestCase):

    def setUp(self):
        # Create a temporary ASCII file for testing
        self.filename = 'file.txt'

    @patch('builtins.open', new_callable=mock_open, read_data='This is a test data')
    def test_read_file(self, mock_file):
        content = read_ascii_file(self.filename)
        expected_content = 'This is a test data'
        self.assertEqual(content, expected_content)
        mock_file.assert_called_once_with(self.filename, 'r')

    @patch('builtins.open', side_effect=FileNotFoundError)
    def test_read_file_raise_file_found_error(self, mock_file):
        with self.assertRaises(FileNotFoundError):
            read_ascii_file(self.filename)
        mock_file.assert_called_once_with(self.filename, 'r')

    def test_split_hyphenated_words(self):
        word = "Hyphenated-Word"
        hyphenated_word_list = split_hyphenated_word(word)
        self.assertTrue(len(hyphenated_word_list) == 2)
        self.assertTrue("Hyphenated" in hyphenated_word_list)
        self.assertTrue("Word" in hyphenated_word_list)

    def test_that_words_can_be_splitted_into_a_list(self):
        file_content = 'The Content of the file\nThe Next Page-Two '
        content_list = split_file_content_into_words(file_content)
        self.assertTrue(len(content_list) > 0)
        self.assertEqual(len(content_list), 9)
        self.assertTrue("the" in content_list)
        self.assertTrue("content" in content_list)
        self.assertTrue("two" in content_list)

    def test_remove_punctuation_from_word(self):
        word_with_quotation = 'The"'
        word_with_question_mark = 'Conten?t'
        word_with_exclamation_mark = 'o!f'
        word_with_bracket = "fil(e"
        word_with_colon = "Nex:t"
        clean_word_without_quotation = remove_punctuations_from_text(word_with_quotation)
        clean_word_without_question_mark = remove_punctuations_from_text(word_with_question_mark)
        clean_word_without_exclamation_mark = remove_punctuations_from_text(word_with_exclamation_mark)
        clean_word_without_bracket = remove_punctuations_from_text(word_with_bracket)
        clean_word_without_colon = remove_punctuations_from_text(word_with_colon)
        self.assertEqual(clean_word_without_quotation, 'The')
        self.assertEqual(clean_word_without_question_mark, 'Content')
        self.assertEqual(clean_word_without_exclamation_mark, 'of')
        self.assertEqual(clean_word_without_bracket, 'file')
        self.assertEqual(clean_word_without_colon, 'Next')

    def test_count_word_occurences(self):
        words = ['hey', 'who', 'are', 'you', 'hey', 'nice', 'to', 'meet', 'you']
        expected_dict = {'hey': 2, 'who': 1, 'are': 1, 'you': 2, 'nice': 1, 'to': 1, 'meet': 1}
        word_dictionary = count_word_occurence(words)
        self.assertEqual(word_dictionary, expected_dict)
        self.assertEqual(word_dictionary['hey'], 2)
        self.assertEqual(word_dictionary['who'], 1)
