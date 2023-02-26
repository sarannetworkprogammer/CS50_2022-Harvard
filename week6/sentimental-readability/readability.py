from cs50 import get_string
import re


# letters count logic
def count_letters(text):
    count = 0
    for letter in text:
        if letter.isupper() or letter.islower():
            count = count + 1
    return count

# words count logic


def count_words(text):
    word_count = 0
    for word in text.rsplit(" "):
        # print(word)
        word_count = word_count + 1
    return word_count

# sentence count logic


def count_sentence(text):

    pattern = "[\.?!]"

    splitstring = re.split(pattern, text)
    sentence_count = len(splitstring) - 1
    return sentence_count


def grade(letters_count, words_count, sentence_count):

    L = (float(letters_count) / float(words_count)) * 100
    S = (float(sentence_count) / float(words_count)) * 100
    index = round((0.0588 * L) - (0.296 * S) - 15.8)
    return index


def main():

    text = get_string("Text: ")

    # print(f"Text: {text}")

    letters_count = count_letters(text)
    # print(letters_count)

    words_count = count_words(text)
    # print(words_count)

    sentence_count = count_sentence(text)
    # print(f"sentence :{sentence_count}")

    index = grade(letters_count, words_count, sentence_count)
    # print(f"index: {index}")

    if index > 16:
        print("Grade 16+")

    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


main()