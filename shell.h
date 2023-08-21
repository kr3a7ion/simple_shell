#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define ENV_SEPARATOR "="
#define ESCAPE_SEPARATOR "#"
#define PATH_SEPARATOR ":"
#define COMMAND_SEPARATOR ";\n"
#define SEPARATORS " \n"
#define PROMPT "$ "

extern char **environ;

typedef struct environment_s
{
    char *name;
    char *value;
    char *global;
    struct environment_s *next;
} environment_t;

typedef struct appData_s
{
    char **arguments;
    char *buffer;
    char *commandName;
    char **commandList;
    char **history;
    char *programName;
    environment_t *env;
} appData_t;

typedef struct errorMessage_s
{
    int code;
    char *msg;
} errorMessage_t;

typedef struct customCommand_s
{
    char *commandName;
    void (*func)(appData_t *);
} customCommand_t;

/* Function Declarations */

// Environment Management
environment_t *_addEnvNodeEnd(environment_t **prmHeadNode, char *prmGlobal);
environment_t *_createEnvNode(char *prmGlobal);
environment_t *_getenv(environment_t *prmEnviron, char *prmName);
void _freeEnvList(environment_t *prmHeadNode);
void _setenv(environment_t *prmEnviron, char *prmName, char *prmValue, int prmOverwrite);
void _unsetenv(appData_t *prmData, char *prmName);

// Command Execution
void _execCommand(appData_t *prmData);
char *_generateAbsolutePath(char *prmPath, char *prmCommandName);
char *_which(appData_t *prmData);

// Memory Management
void *_calloc(unsigned int prmNumber, unsigned int prmSize);
void _freeCharDoublePointer(char **prmPtr);
void _freeAppData(appData_t *prmData);

// String Manipulation
void _addWord(char *prmWord, int *prmIndex, char **prmArray);
char *_cleanString(char *prmString);
char *_generateEnvGlobal(char *prmName, char *prmValue);
char *_getenvname(char *prmVariable);
char *_getenvvalue(char *prmVariable);
char *_memcpy(char *prmDest, char *prmSrc, unsigned int prmLimit);
char *_memset(char *prmString, char prmCharacter, unsigned int prmLimit);
char *_strcat(char *prmDest, char *prmSrc);
int _strcmp(char *prmString1, char *prmString2);
char *_strcpy(char *prmDest, char *prmSrc);
char *_strconcat(char *prmString1, char *prmString2);
char *_strncpy(char *prmDest, char *prmSrc, int prmLimit);
unsigned int _strcspn(char *prmString, char *prmDeny);
char *_strdup(char *prmString);
int _strlen(char *prmStr);
char *_strstr(char *prmHaystack, char *prmNeedle, int prmBegin);

// Other Functions
void _cdHelp(void);
void _changeDirectory(appData_t *prmData);
void _changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory);
void _changeToHomeDirectory(appData_t *prmData, char *prmCurrentDirectory);
void _changeToPreviousDirectory(appData_t *prmData, char *prmCurrentDirectory);
int _checkEndCharacter(char *prmString);
int _checkEscapeSeparators(char prmChar, char *prmEscapeSeparators);
int _checkSeparators(char prmChar, char *prmSeparators);
int _atoi(char *prmString);
void _ctrlC(int prmSignal);
void _defaultHelp(char *prmCommand);
void _env(appData_t *prmData);
void _envHelp(void);
void _errorHandler(appData_t *prmData, int messageCode);
void _exitStatus(appData_t *prmData);
void _exitHelp(void);
void _getline(appData_t *prmData);
void _help(appData_t *prmData);
void _helpHelp(void);
int _inArray(char prmChar, char *prmArray);
appData_t *_initData(char **prmArgv);
void _initEnvData(appData_t *prmData);
int _isdigit(char prmChar);
int _isNumber(char *s);
char *_itoa(int prmNumber);
int _listEnvLen(environment_t *prmHead);
int _nbrLen(int prmNumber);
char **_parsingPathEnvironment(appData_t *prmData);
void _printenv(environment_t *prmEnviron);
int _putchar(char prmChar);
int _puts(char *prmStr);
void *_realloc(void *prmPtr, unsigned int prmOldSize, unsigned int prmNewSize);
void _setEnvironment(appData_t *prmData);
void _setenvHelp(void);
void _unsetEnvironment(appData_t *prmData);
int _wordNumber(char *prmString, char *prmSeparators);

#endif
