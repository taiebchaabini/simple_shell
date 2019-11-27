#include "simple.h"
/**
 * _which - Function to check if the program exist in PATH directories
 * @path: filename to check
 * @buf: buffer
 * @count: number of times command are executed
 * @av: name of the shell file
 * Return: Pointer to the found path, otherwise null
 **/
char *_which(const char *path, struct stat *buf, int count, char *av)
{
	struct stat st;
	int i = 0;
	char *value = NULL, *token = NULL, *state = NULL, *pathtmp = NULL;

	if (_strcmp(path, "\n") == 0)
		return (NULL);
	if (path == NULL || buf == NULL)
	{
		printf("ERROR : %s\n", path);
		return (NULL);
	}
	value = _getenv("PATH");
	if (value != NULL)
	{
		token = malloc(sizeof(char) * _strlen(value) + 1);
		if (token == NULL)
		{
			_error("Error: Token - malloc in _which function");
			exit(-1);
		}
		token = strtok(value, ":\n");
	}
	pathtmp = _strdup(path);
	while (token != NULL || value == NULL)
	{
		if (stat(path, &st) == 0 || stat(path, &st) == 0 && value == NULL)
			return (pathtmp);
		token = str_concat(str_concat(token, "/"), pathtmp);
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
 * _error - Write a message in the standard error output
 * @msg: Message that should be displayed
 **/
void _error(char *msg)
{
	write(2, msg, _strlen(msg));
}
