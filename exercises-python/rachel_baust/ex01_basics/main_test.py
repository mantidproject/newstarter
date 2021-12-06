import io
import unittest.mock
import main


class MainTest(unittest.TestCase):

    def test_read_content_of_invalid_filename_returns_None(self):
        self.assertIsNone(main.read_content(''))

    def test_create_word_dictionary_is_correct_output(self):
        content = ['some Lines of text (for testing)', 'punctuation like !"-\'., should be removed', 'hyphenated-words',
                   'apostrophe\'s', 'punctuation']
        expected_dict = {'lines': 1, 'testing': 1, 'punctuation': 2, 'should': 1, 'removed': 1, 'hyphenated': 1,
                         'words': 1, 'apostrophes': 1}
        actual_dict = main.create_word_dictionary(content)
        self.assertDictEqual(expected_dict, actual_dict)

    def test_create_word_dictionary_returns_empty_dictionary_for_no_content(self):
        actual_dict = main.create_word_dictionary([])
        self.assertDictEqual({}, actual_dict)

    @unittest.mock.patch('sys.stdout', new_callable=io.StringIO)
    def test_print_list_output_is_correct(self, mock_stdout):
        test_heading = 'a heading for the test'
        test_tuple_list = [('words', 30), ('testing', 4), ('mocking', 1)]
        main.print_list(test_heading, test_tuple_list)
        actual_output = io.StringIO(mock_stdout.getvalue()).readlines()
        self.assertEqual(len(test_tuple_list) + 1, len(actual_output))
        self.assertEqual(actual_output[0], f'{test_heading}\n')
        index = 1
        for key, value in test_tuple_list:
            actual_values = actual_output[index].split()
            self.assertEqual(key, actual_values[0])
            self.assertEqual(value, int(actual_values[1]))
            index += 1


if __name__ == '__main__':
    unittest.main()
