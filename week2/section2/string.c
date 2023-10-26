#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = "Emma";
    int lenght = strlen(name);

    for (int i = 0; i < lenght; i++)
    {
        printf("%i ", name[i]);
    }
    printf("\n");
}