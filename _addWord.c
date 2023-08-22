/**
 * _addWord - add a cleaned word to an array
 *
 * @prmWord: word to add
 * @prmIndex: current index
 * @prmArray: array
 */
void _addWord(char *prmWord, int *prmIndex, char **prmArray)
{
    // Clean the string before adding to the array
    char *cleanedWord = _cleanString(prmWord);

    // Duplicate and store the cleaned word in the array
    prmArray[*prmIndex] = _strdup(cleanedWord);

    // Update index and free memory
    *prmIndex += 1;
    free(cleanedWord);
}

