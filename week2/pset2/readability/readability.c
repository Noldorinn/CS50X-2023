#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string get_text = get_string("Text: ");

    int cl = count_letters(get_text);
    int cw = count_words(get_text);
    int cs = count_sentences(get_text);

    // Letter/Word * 100 and Sentence/Word * 100
    float average_letter = (float) cl / cw * 100;
    float average_sentences = (float) cs / cw * 100;

    // Print Grade X
    float index = 0.0588 * average_letter - 0.296 * average_sentences - 15.8;

    int i = round(index);
    if (i >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    // printf("%i letters\n",count);
    return count;
}

int count_words(string text)
{
    int count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    // printf("%i words\n",count);
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    // printf("%i sentences\n",count);
    return count;
}