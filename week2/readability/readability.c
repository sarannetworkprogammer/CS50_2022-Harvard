#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentence(string text);
int grade(int letters_count, int words_count, int sentence_count);


// main function execution


int main(void)
{

    string text = get_string("enter the book or sententces you want to grade ");
    printf("Text: %s\n", text);

    int letters_count = count_letters(text);
//printf("letters_count = %i\n",letters_count);
    int words_count = count_words(text);

//printf("words_count= %i\n",words_count);


    int sentence_count = count_sentence(text);

//printf("sentence_count= %i\n",sentence_count);

// printing grade
    int index = grade(letters_count, words_count, sentence_count);
//printf("index = %i\n", index);

    if (index > 16)
    {
        printf("Grade 16+\n");

    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

//counting letters logic

int count_letters(string text)
{
    int letters_count = 0;
    int len = strlen(text);
    //printf("%i\n",len);
    for (int i = 0; i < len; i++)
    {
        //printf("%c\n",text[i]);
        if (isupper(text[i]) || islower(text[i]))
        {
            letters_count++;
        }
    }
    return letters_count;
}

// counting words logic

int count_words(string text)
{
    int words_count = 1;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            words_count++;
        }
    }
    return words_count;

}

// counting Sentence logics to be written here

int count_sentence(string text)
{
    int sentence_count = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {

            sentence_count++;
        }
    }

    return sentence_count;

}


int grade(int letters_count, int words_count, int sentence_count)

{

    float L = ((float)letters_count / (float)words_count) * 100;
    float S = ((float)sentence_count / (float)words_count) * 100;
    int  index = round((0.0588 * L) - (0.296 * S) - 15.8);
    return index;

}