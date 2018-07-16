#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool isLowerCaseLetter(char c)
{
    int asciiCode = (int) c;
    return (asciiCode >= 97 && asciiCode <= 122);
}

bool isUpperCaseLetter(char c)
{
    int asciiCode = (int) c;
    return (asciiCode >= 65 && asciiCode <= 90);
}

bool isVigenereKeyValid(int argCount, string argArray[])
{
    if (argCount != 2)
    {
        return false;
    }

    // check every char - reject if string contains anything besides upper/lower case letters
    for (int i = 0; i < strlen(argArray[1]); i++)
    {
        char currentKeyChar = argArray[1][i];
        if (!isLowerCaseLetter(currentKeyChar) && !isUpperCaseLetter(currentKeyChar))
        {
            return false;
        }
    }

    return true;
}

int convertCharToKey(char c, bool isCharLowerCase)
{
    int offset = isCharLowerCase ? 97 : 65;
    return (int) c - offset;
}

char convertPlainCharToCipherChar(char plainChar, int key, bool isCharLowerCase)
{
    int offset = isCharLowerCase ? 97 : 65;
    return (char) offset + ((int) plainChar + key - offset) % 26;
}

int printVigenereKeyError()
{
    printf("Usage: ./vigenere key\n");
    return 0;
}

int main(int argCount, string argArray[])
{
    // validate vigenere key
    if (!isVigenereKeyValid(argCount, argArray))
    {
        printVigenereKeyError();
        return 1;
    }

    string vigenereKey = argArray[1];
    int keyLength = strlen(vigenereKey);
    int currentKeyIndex = 0;

    // get user input for plain text
    string plainText = get_string("plainText: ");
    int plainTextLength = strlen(plainText);

    printf("ciphertext: ");
    // convert plain text to cipher, skipping over non-alphabetical chars
    for (int i = 0; i < plainTextLength; i++)
    {
        char currentChar = plainText[i];
        char convertedChar;
        if (isLowerCaseLetter(currentChar) || isUpperCaseLetter(currentChar))
        {
            int currentKey = convertCharToKey(vigenereKey[currentKeyIndex], isLowerCaseLetter(vigenereKey[currentKeyIndex]));
            convertedChar = convertPlainCharToCipherChar(currentChar, currentKey, isLowerCaseLetter(currentChar));

            // printf("curr = %c, key = %i, conv = %c\n", currentChar, currentKey, convertedChar);

            // if at the end of the key, go back to the first char
            currentKeyIndex = (currentKeyIndex + 1 == keyLength) ? 0 : currentKeyIndex + 1;

        }
        else
        {
            // no key change if the current char was not a letter
            convertedChar = currentChar;
        }
        printf("%c", convertedChar);
    }

    printf("\n");
    return 0;
}