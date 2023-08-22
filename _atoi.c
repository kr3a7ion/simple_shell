#include "shell.h"

/**
 * _atoi - to convert a string to an integer.
 *
 * @prmString: a char pointer
 *
 * Return: an int
 */
int _atoi(char *prmString)
{
    int sign = 1, cLoop = 0;
    unsigned int number = 0;

    if (prmString[cLoop] == '-')
    {
        sign = -1;
        cLoop++;
    }

    while (prmString[cLoop] != '\0')
    {
        char current = prmString[cLoop];

        if (_isdigit(current))
        {
            number = number * 10 + (current - '0');
        }
        else if (current == '-' && cLoop == 0)
        {
            // Allow negative sign at the beginning
            sign = -sign;
        }
        else if (number > 0)
        {
            // Stop parsing after encountering digits
            break;
        }

        cLoop++;
    }

    return sign * number;
}
