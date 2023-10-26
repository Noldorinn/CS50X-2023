#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string m = get_string("Message: ");
    for (int i = 0; i < strlen(m); i++)
    {
        int k = m[i];
        int ar[BITS_IN_BYTE] = {0, 0, 0, 0, 0, 0, 0, 0};
        for (int j = 1; j < BITS_IN_BYTE; j++)
        {
            ar[BITS_IN_BYTE - j] = (k % 2);
            k /= 2;
        }

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(ar[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
