import sys
import re
from collections import Counter


def get_file_name_from_command_line():
    try:
        filename = sys.argv[1]
        return filename
    except IndexError:
        raise ValueError(f"no commandline argument for filename was provided")


def read_ascii_file(filename):
    try:
        f = open(filename, 'r')
        content = f.read()
        f.close()
        return content
    except FileNotFoundError:
        raise FileNotFoundError(f"The file {filename} was not found.")


def split_hyphenated_word(word):
    return word.split("-")


def remove_punctuations_from_text(word):
    clean_word = re.sub(r'[.,?\'"!():]', '', word)
    return clean_word


def split_file_content_into_words(file_content):
    word_list = []
    for word in file_content.split():
        word = word.lower()
        word = remove_punctuations_from_text(word)
        hyphenated_word_list = split_hyphenated_word(word)
        word_list.extend(hyphenated_word_list)

    return word_list


def count_word_occurence(words):
    word_counts = Counter(words)
    for word, count in word_counts.items():
        print(f'{word:<15} {count}')
    return word_counts


def main():
    try:
        filename = get_file_name_from_command_line()
        file_content = read_ascii_file(filename)
        words = split_file_content_into_words(file_content)
        count_word_occurence(words)
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found.")
    except ValueError as e:
        print(e)


if __name__ == "__main__":
    main()
