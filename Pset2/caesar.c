#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argCount, string argArray[])
{
    // ensure correct number of arguments were provided
    if (argCount != 2)
    {
        return 1;
    }

    int key = atoi(argArray[1]) % 26;
    printf(" input = %s %i\n", argArray[1], key);

    // get user string input
    string plainText = get_string("plaintext: ");
    int inputLength = strlen(plainText);

    // calculate ciper letters and print them
    printf("ciphertext: ");
    for (int i = 0; i < inputLength; i++)
    {
        int asciiCode = (int) plainText[i];

        // printf("Before cipher: %i, %c\n", asciiCode, plainText[i]);

        // lower case letters
        if (asciiCode >= 65 && asciiCode <= 90)
        {
            asciiCode = 65 + ((asciiCode - 65 + key) % 26);
        }

        // upper case letters
        if (asciiCode >= 97 && asciiCode <= 122)
        {
            asciiCode = 97 + ((asciiCode - 97 + key) % 26);
        }

        printf("%c", (char) asciiCode);

        // no conversion for non-alphabet characters
        // printf("%c = %i\n", plainText[i], (int) plainText[i]);
        // printf("After cipher: %i, %c\n", asciiCode, (char) asciiCode);
    }
    printf("\n");

    return 0;
}