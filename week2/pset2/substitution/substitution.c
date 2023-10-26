#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_alpha(string key);
bool only_different(string key);
string replace(string key, string plain);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26 || !only_alpha(argv[1]) || !only_different(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plain_text = get_string("plaintext:  ");
    string chipper_text = replace(argv[1], plain_text);

    printf("ciphertext: %s\n", chipper_text);
}

bool only_alpha(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]))
        {
            return true;
        }
    }
    return false;
}

bool only_different(string key)
{
    string numbers[26] = {0};
    for (int i = 0; i < strlen(key); i++)
    {
        char c = tolower(key[i]);
        if (numbers[c - 'a'] > 0)
        {
            return false;
        }
        numbers[c - 'a']++;
    }
    return true;
}

string replace(string key, string plain)
{
    string chipher = plain;

    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            char c = tolower(plain[i]);
            int index = c - 'a';
            if (isupper(plain[i]))
            {
                chipher[i] = toupper(key[index]);
            }
            else
            {
                chipher[i] = tolower(key[index]);
            }
        }
    }
    return chipher;
}