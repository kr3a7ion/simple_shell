#include "shell.h"

/**
 * _cdHelp - print help for cd command
 */
void _cdHelp(void)
{
    _puts("cd: cd [-L|[-P [-e]] [-@]] [dir]");
    _puts("    Change the shell working directory.");
    _puts("    Change the current directory to DIR. The default DIR");
    _puts("    is the value of the HOME shell variable.");
    _puts("    The variable CDPATH defines the search path for the directory containing");
    _puts("    DIR. Alternative directory names in CDPATH are separated by a colon (:).");
    _puts("    A null directory name is the same as the current directory. If DIR begins");
    _puts("    with a slash (/), then CDPATH is not used.");
    _puts("    If the directory is not found, and the shell option `cdable_vars' is set,");
    _puts("    the word is assumed to be a variable name. If that variable has a value,");
    _puts("    its value is used for DIR.");
    _puts("Options:");
    _puts("        -L      force symbolic links to be followed: resolve");
    _puts("                symbolic links in DIR after processing instances of `..'");
    _puts("        -P      use the physical directory structure without following symbolic");
    _puts("                links: resolve symbolic links in DIR before processing instances");
    _puts("                of `..'");
    _puts("        -e      if the -P option is supplied, and the current working directory");
    _puts("                cannot be determined successfully, exit with a non-zero status");
    _puts("        -@      on systems that support it, present a file with extended attributes");
    _puts("                as a directory containing the file attributes");
    _puts("The default is to follow symbolic links, as if `-L' were specified.");
    _puts("`..' is processed by removing the immediately previous pathname");
    _puts("component back to a slash or the beginning of DIR.");
    _puts("Exit Status:");
    _puts("    Returns 0 if the directory is changed, and if $PWD is set successfully when");
    _puts("    -P is used; non-zero otherwise.");
}
