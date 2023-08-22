/**
 * _checkSeparators - check if a character corresponds to one of the separators
 *                    or the EOF character
 *
 * @prmChar: character to compare
 * @prmSeparators: list of separators
 *
 * Return: 0 if not found, 1 if found
 */
int _checkSeparators(char prmChar, char *prmSeparators)
{
    if (prmSeparators == NULL) {
        return 0;
    }

    return _inArray(prmChar, prmSeparators) || (prmChar == '\0');
}

