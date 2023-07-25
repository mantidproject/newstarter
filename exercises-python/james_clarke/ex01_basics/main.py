import re


def main(input_file = "C:/Mantid/Newstarter/newstarter/exercises-python/james_clarke/ex01_basics/Holmes.txt"):
    splitter = "[ -.,?'\"!():\n]"
    word_counter = {}

    with open(input_file, "r") as file:
        for line in file:
            extract_words_from_line(line, splitter, word_counter)

    words_ordered_by_frequency = sorted(word_counter, key=word_counter.get, reverse=True)
    length_of_longest_word = len(max(words_ordered_by_frequency, key=len))

    print("Word" + padding("Word", length_of_longest_word) + "Usage")
    for word in words_ordered_by_frequency:
        print(word + padding(word, length_of_longest_word) + str(word_counter[word]))


def extract_words_from_line(line_text: str, splitter: str, word_counter: dict[str, int]):
    split_line = re.split(splitter, line_text)
    for word in split_line:
        lower_word = word.lower()
        if len(lower_word) > 4:
            if lower_word not in word_counter:
                word_counter[lower_word] = 1
            else:
                word_counter[lower_word] += 1


def padding(word: str, target_length: int) -> str:
    return ' '*(target_length-len(word))


if __name__ == "__main__":
    main()
