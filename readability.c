#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get input text
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = 0, S = 0, index = 0;

    L = (100.0*letters)/words;
    S = (100.0*sentences)/words;

    index = 0.0588*L - 0.296*S - 15.8;
    int round_index = round(index);

    //results
    if(round_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(round_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else printf("Grade %i\n", round_index);

}

int count_letters(string text)
{
    int counter = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            counter++;
        }
        else continue;
    }
    return counter;
}

int count_words(string text)
{
    int counter = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            counter++;
        }
        else continue;
    }
    return counter;
}

int count_sentences(string text)
{
    int counter = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
        else continue;
    }
    return counter;
}