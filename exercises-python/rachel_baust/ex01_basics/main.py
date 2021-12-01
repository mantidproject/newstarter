#!/usr/bin/env python3
from re import split
from os.path import exists
import argparse


def main():
    parser = argparse.ArgumentParser(description='Count words from a file')
    parser.add_argument('filename', help='The path to the file')
    args = parser.parse_args()

    file_content = read_content(args.filename)
    if file_content is not None:
        word_count = create_word_dictionary(file_content)
        print_list('Word   Usage\n', sorted(word_count.items(), key=lambda x: x[1], reverse=True))


def read_content(filename):
    if exists(filename):
        with open(filename, mode='rt', encoding='utf-8') as file:
            return file.readlines()
    else:
        print("Could not read file contents. No file could be found at: {0}".format(filename))
        return None


def create_word_dictionary(content):
    word_count = {}
    for line in content:
        words = split(r'\W+', line.replace("\'", ''))
        for word in words:
            if len(word) > 4:
                if word.casefold() in word_count:
                    word_count[word.casefold()] += 1
                else:
                    word_count[word.casefold()] = 1
    return word_count


def print_list(heading, dictionary):
    print(heading)
    for key, value in dictionary:
        print(key, '   ', value)


if __name__ == "__main__":
    main()
