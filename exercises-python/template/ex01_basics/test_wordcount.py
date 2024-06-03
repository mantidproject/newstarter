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



