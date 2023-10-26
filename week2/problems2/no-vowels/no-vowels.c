// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{
    string result = replace(argv[1]);
    printf("%s\n", result);
}

string replace(string input)
{
    int n = strlen(input);
    string replaced_string = input;

    for (int i = 0; i < n; i++)
    {
        switch (input[i])
        {
            case 'a':
                replaced_string[i] = '6';
                break;
            case 'e':
                replaced_string[i] = '3';
                break;
            case 'i':
                replaced_string[i] = '1';
                break;
            case 'o':
                replaced_string[i] = '0';
                break;
        }
    }
    return replaced_string;
}