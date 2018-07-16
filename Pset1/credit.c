#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool luhnCheck(long long number)
{
    int evens = 0;
    int odds = 0;
    bool isOdd = true;
    while (number > 0)
    {
        int digit = fmod(number, 10);

        if (isOdd)
        {
            odds = odds + digit;
        }
        else
        {
            int newDigit = digit;
            newDigit = newDigit * 2;
            if (newDigit > 9)
            {
                newDigit = newDigit - 9;
            }
            evens = evens + newDigit;
        }
        isOdd = !isOdd;
        number = ((number - digit) / 10);
    }

    return (((odds + evens) % 10) == 0);
}

int main(void)
{
    // get number from user
    long long creditCardNumber;
    do
    {
        creditCardNumber = get_long_long("Number: ");
    }
    while (creditCardNumber <= 0);


    /* next, check validity of number

        numbers less than 13 digits or more than 16 digits are invalid
        numbers with 13/15/16 digits may be valid, depending on two factors:
            1) whether most significant 1-2 digits match a company's predetermined format
                AMEX = 15 digits, starts with 34 or 37
                MC = 16 digits, starts with 51-55 inclusive
                VISA = either 13 or 16 digits, starts with 4
            2) if it meets checksum defined by Luhn's aglorithm
    */

    if (creditCardNumber <= 3999999999999)
    {
        printf("INVALID\n");
    }
    else if (creditCardNumber <= 4999999999999)
    {
        if (luhnCheck(creditCardNumber))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (creditCardNumber <= 339999999999999)
    {
        printf("INVALID\n");
    }
    else if (creditCardNumber <= 349999999999999)
    {
        if (luhnCheck(creditCardNumber))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (creditCardNumber <= 369999999999999)
    {
        printf("INVALID\n");
    }
    else if (creditCardNumber <= 379999999999999)
    {
        if (luhnCheck(creditCardNumber))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (creditCardNumber <= 3999999999999999)
    {
        printf("INVALID\n");
    }
    else if (creditCardNumber <= 4999999999999999)
    {
        if (luhnCheck(creditCardNumber))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (creditCardNumber <= 5099999999999999)
    {
        printf("INVALID\n");
    }
    else if (creditCardNumber <= 5599999999999999)
    {
        if (luhnCheck(creditCardNumber))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}