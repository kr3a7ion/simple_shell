/**
 * _changeDirectory - change current directory
 *
 * @prmData: data structure
 */
void _changeDirectory(appData_t *prmData)
{
    char currentDirectory[500];

    // Get the current directory
    getcwd(currentDirectory, sizeof(currentDirectory));

    if (prmData != NULL)
    {
        if (!prmData->arguments[1] ||
            _strcmp(prmData->arguments[1], "~") == 0 ||
            _strcmp(prmData->arguments[1], "~/") == 0)
        {
            _changeToHomeDirectory(prmData, currentDirectory);
        }
        else if (_strcmp(prmData->arguments[1], "-") == 0)
        {
            _changeToPreviousDirectory(prmData, currentDirectory);
        }
        else
        {
            _changeToAnyDirectory(prmData, currentDirectory);
        }
    }
}

