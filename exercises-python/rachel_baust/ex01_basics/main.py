#!/usr/bin/env python3
from re import split
import argparse


def main():
    parser = argparse.ArgumentParser(description='Count words from a file')
    parser.add_argument('filename', help='The path to the file')
    args = parser.parse_args()

    file_content = read_content(args.filename)
    word_count = create_word_dictionary(file_content)
    print_list('Word   Usage\n', sorted(word_count.items(), key=lambda x: x[1], reverse=True))


def read_content(filename):
    try:
        file = open(filename, mode='rt', encoding='utf-8')
        return file.readlines()
    finally:
        file.close()


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
