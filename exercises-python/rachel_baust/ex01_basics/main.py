#!/usr/bin/env python3
from re import split
from collections import defaultdict
import argparse


def main():
    parser = argparse.ArgumentParser(description='Count words from a file')
    parser.add_argument('filename', help='The path to the file')
    args = parser.parse_args()

    file_content = read_content(args.filename)
    if file_content is not None:
        word_count = create_word_dictionary(file_content)
        print_list('Word   Usage', sorted(word_count.items(), key=lambda x: x[1], reverse=True))


def read_content(filename):
    """
    Reads in all the lines from the file at the given path
    :param filename: the path to the file to be read
    :return: list[str] or None if the file couldn't be found
    """
    try:
        with open(filename, mode='rt', encoding='utf-8') as file:
            return file.readlines()
    except FileNotFoundError:
        print("Could not read file contents. No file could be found at: {0}".format(filename))
        return None
    except OSError as e:
        print("Error occurred when attempting to open file: {0}\nException: {1}".format(filename, str(e)))
        return None


def create_word_dictionary(content):
    """
    Transforms the given list of strings into a dictionary that gives the number of times each word appears
    The final count is case and punctuation insensitive
    :param content: the list of strings to be transformed
    :return: dictionary of words to the count
    """
    word_count = defaultdict(int)
    for line in content:
        words = split(r'\W+', line.replace("\'", ''))
        for word in words:
            if len(word) > 4:
                word_count[word.casefold()] += 1
    return word_count


def print_list(heading, tuple_list):
    """
    Prints a heading and the contents of the given list of tuples to the console
    :param heading: the heading to be printed above the list contents
    :param tuple_list: the list of tuples to be printed
    :return: output is printed to the console
    """
    print(heading)
    for key, value in tuple_list:
        print(key, '   ', value)


if __name__ == "__main__":
    main()
