#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])

{
    while (argc != 2) // checking 2 argumetns present or not printing error message

    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    for (int j = 0; j < strlen(argv[1]) ; j++)
    {
        if (!(isdigit(argv[1][j]))) //checking its a number
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    string word = get_string("plaintext:  "); // taking input plaintext
    int len = strlen(word); // length of word
    printf("ciphertext: ");
    int a, b;


    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i])) // converting upper case to ascii
        {
            b = (word[i
            printf("%c", b + 65);


        }
        else if (islower(word[i])) //converting lower case to ascii
        {
            b = (word[i] - 97 + atoi(argv[1])) % 26;
            printf("%c", b + 97);
        }
        else
        {
            printf("%c", word[i]); // printing same characters as it is
        }
    }
printf("\n");
return 0;
}
