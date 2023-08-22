/**
 * _atoi - convert a string to an integer.
 *
 * @prmString: char pointer
 *
 * Return: int
 */
int _atoi(char *prmString)
{
    char sign = 1;
    int size = _strlen(prmString);
    int cLoop;
    unsigned int number = 0;

    for (cLoop = 0; cLoop < size; cLoop++)
    {
        char current = prmString[cLoop];

        if (_isdigit(current))
        {
            number = number * 10 + (current - '0');
        }
        else if (current == '-')
        {
            sign = -sign;
        }
        else if (number > 0)
        {
            break; // Stop if non-digit follows digits
        }
    }

    return sign * number;
}

