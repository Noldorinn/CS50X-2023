#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Get key
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    // Get plaintext
    string pt = get_string("plaintext:  ");

    // Encipher
    string ct = pt;
    for (int i = 0; i < strlen(ct); i++)
    {
        ct[i] = rotate(ct[i], key);
    }

    // Print ciphertext
    printf("ciphertext: %s\n", ct);
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        char rotate = c - 'A';
        char r = (rotate + n) % 26;
        return r + 'A';
    }
    else if (islower(c))
    {
        char rotate = c - 'a';
        char r = (rotate + n) % 26;
        return r + 'a';
    }
    else
    {
        return c;
    }
}