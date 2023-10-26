#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the lenght from user
    int lenght;
    do
    {
        lenght = get_int("Lenght: ");
    }
    while (lenght < 1);

    // Declare our array
    int twice[lenght];

    // Set the first value
    twice[0] = 1;
    printf("%i\n", twice[0]);

    for (int i = 1; i < lenght; i++)
    {
        // Make the current element twice the previous
        twice[i] = 2 * twice[i - 1];

        // Print the current element
        printf("%i\n", twice[i]);
    }


}