#include "shell.h"

/**
 * _addWord - Add a cleaned  word to an array
 *
 * @prmWord: The word to add
 * @prmIndex: Pointer to the current index
 * @prmArray: The string array
 */
void _addWord(char *prmWord, int *prmIndex, char **prmArray)
{
	prmWord = _cleanString(prmWord);
	prmArray[*prmIndex] = _strdup(prmWord);
	free(prmWord);
	(*prmIndex)++;
}
