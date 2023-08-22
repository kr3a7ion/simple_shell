/**
 * _exitHelp - print help information for the exit command
 */
void _exitHelp(void)
{
    _puts("exit: exit [n]\n"
          "    Exit the shell.\n\n"
          "    Exits the shell with a status of N. "
          "If N is omitted, the exit status\n"
          "    is that of the last command executed.\n");
}

