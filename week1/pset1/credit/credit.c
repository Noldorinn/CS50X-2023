#include <cs50.h>
#include <stdio.h>

long get_number(void);
bool checksum(long number);
int card_lenght(long number);
int get_starting_digits(long number);
void show_name(bool check, int lenght, int starting_digits);

int main(void)
{
    // TO DO Prompt for input.
    long number = get_number();

    // TO DO Calculate checksum.
    bool c = checksum(number);

    // TO DO Check for card lenght and starting digits.
    int l = card_lenght(number);
    int d = get_starting_digits(number);
    // TO DO Print AMEX, MASTERCARD, VISA, INVALID
    show_name(c, l, d);
}

long get_number(void)
{
    long a = get_long("Number: ");
    return a;
}

bool checksum(long number)
{
    int sum = 0;
    int bytwo = 0;

    while (number > 0)
    {
        int last = number % 10;

        if (bytwo)
        {
            last *= 2;

            if (last > 9)
            {
                last = last % 10 + last / 10;
            }
        }

        sum += last;
        bytwo = !bytwo;
        number /= 10;
    }

    return sum % 10 == 0;
}

int card_lenght(long number)
{
    int lenght = 0;
    while (number > 0)
    {
        number /= 10;
        lenght++;
    }

    return lenght;
}

int get_starting_digits(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }

    return number;
}

void show_name(bool check, int lenght, int starting_digits)
{
    if (!check)
    {
        printf("INVALID\n");
        return;
    }

    if (lenght == 15 && (starting_digits == 34 || starting_digits == 37))
    {
        printf("AMEX\n");
    }
    else if ((lenght == 13 || lenght == 16) && (starting_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else if (lenght == 16 && (starting_digits == 51 || starting_digits == 52 || starting_digits == 53 || starting_digits == 54 ||
                              starting_digits == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
