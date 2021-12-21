#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int get_index(string s);
int main()
{
    string text = get_string("Text: ");
    int index = get_index(text);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);

    }
    return 0;
}

int get_index(string s)
{
    int letters = 0;
    int sentence = 0;
    int  words = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        char ch = s[i];
        if (isalpha(ch))
        {
            letters++;
        }
        if (isspace(ch))
        {
            words++;
        }
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentence++;
        }
    }
    words++;
    float L = (letters * 100.f) / words;
    float S = (sentence  * 100.f) / words;
    return  round(0.0588 * L - 0.296 * S - 15.8);

}
