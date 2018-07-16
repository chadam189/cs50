#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int pyramidHeight;

    // prompt user for positive non-zero number between 1 and 23 inclusive
    do
    {
        pyramidHeight = get_int("Height: ");
    }
    while (pyramidHeight < 0 || pyramidHeight > 23);

    // print the pyramids, row by row!
    for (int rowNumber = 0; rowNumber < pyramidHeight; rowNumber++)
    {
        // print the left pyramid first
        for (int j = 0; j < pyramidHeight; j++)
        {
            if (j < pyramidHeight - rowNumber - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        // spaces to separate the left and right pyramid
        printf("  ");

        // print the right pyramid blocks, but not any trailing spaces!
        for (int k = 0; k < pyramidHeight; k++)
        {
            if (k <= rowNumber)
            {
                printf("#");
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
}