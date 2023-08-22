/**
 * _checkEscapeSeparators - check if character corresponds to one of escape
 *                          separators
 *
 * @prmChar: character to compare
 * @prmEscapeSeparators: list of separators
 *
 * Return: 0 if not found, 1 if found
 */
int _checkEscapeSeparators(char prmChar, char *prmEscapeSeparators)
{
    if (prmEscapeSeparators == NULL) {
        return 0;
    }

    return _inArray(prmChar, prmEscapeSeparators);
}

