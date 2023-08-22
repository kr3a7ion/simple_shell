/**
 * _changeToHomeDirectory - change to home directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void _changeToHomeDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
    environment_t *homeDirectory = _getenv(prmData->env, "HOME");

    if (access(homeDirectory->value, R_OK | W_OK) == 0) {
        chdir(homeDirectory->value);
        _setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
    } else {
        perror(homeDirectory->value);
    }
}

