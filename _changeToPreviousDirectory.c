/**
 * _changeToPreviousDirectory - change to previous directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void _changeToPreviousDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
    environment_t *previousDirectory = _getenv(prmData->env, "OLDPWD");

    if (access(previousDirectory->value, R_OK | W_OK) == 0) {
        chdir(previousDirectory->value);
        _setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
    } else {
        perror(previousDirectory->value);
    }
}

