#include "simple.h"
/**
 * _which - checks if the program exist in PATH directories
 * @path: takes string filename to check
 * @buf: buffer
 * @count: takes number of times command are executed
 * @av: name of the shell file
 * Return: Pointer to the found path, otherwise null
 **/
char *_which(const char *path, struct stat *buf, __attribute__ ((unused))
		int count, char *av)
{
	struct stat st = {0};
	char *value = NULL, *token = NULL, *pathtmp = NULL;

	if (_strcmp(path, "\n") == 0)
		return (NULL);
	if (path == NULL || buf == NULL)
		return (NULL);
	value = _getenv("PATH");
	if (value != NULL)
	{
		token = _calloc(_strlen(value), sizeof(value));
		if (token == NULL)
			return (NULL);
		token = strtok(value, ":\n");
	}
	pathtmp = _strdup(path);
	while (token != NULL || value == NULL)
	{
		if ((stat(path, &st) == 0) || (stat(path, &st) == 0 && value == NULL))
			return (pathtmp);
		token = str_concat(token, "/");
		token = str_concat(token, pathtmp);
		if (stat(token, &st) == 0)
			return (token);
		if (stat(token, &st) != 0 && value == NULL)
			break;
		token = strtok(NULL, ":\n");
	}
	perror(av);
	return (NULL);
}
/**
 * _error - Writes a message in the standard error output
 * @msg: Message that should be displayed
 **/
void _error(char *msg)
{
	write(2, msg, _strlen(msg));
}
/**
* _shsign - Prints the shell sign in interactive mode
**/
void _shsign(void)
{
	if (isatty(STDIN_FILENO))
		_puts("($) ", 0);
}
