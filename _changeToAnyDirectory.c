#include "shell.h"

/**
 * _changeToAnyDirectory - to change to any directory
 *
 * @prmData: the data structure
 * @prmCurrentDirectory: the current directory path
 */
void _changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
    char *newDirectory = prmData->arguments[1];

    if (access(newDirectory, R_OK | W_OK) == 0)
    {
        chdir(newDirectory);
        _setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
    }
    else
    {
        perror(newDirectory);
    }
}
