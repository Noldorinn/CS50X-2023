#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_grid(int n);

int main(void)
{
    int n = get_height();
    print_grid(n);
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (1 > n || n > 9);

    return n;
}

void print_grid(height)
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < ((height - i) - 1); j++)
        {
            printf(" ");
        }
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}