#include "simple.h"
/*
 * _which - function to check if the program exist in PATH directories
 * @argv0: filename to check
 * @st: buffer
 **/
char *_which(const char *path, struct stat *buf, int count, char *av)
{
	struct stat st;
	int i = 0;
	char *value = NULL, *token = NULL;
	char *state = NULL, *pathtmp = NULL;

	if (path == NULL || buf == NULL)
	{
		return (NULL);
	}
	value = _getenv("PATH");
	if (value != NULL)
	{
		token = malloc(sizeof(char) * _strlen(value));
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
		//pathtemp = strtok(pathtemp, " \n");
		token = str_concat(str_concat(token, "/"), pathtmp);
		if (stat(token, &st) == 0)
			return (token);
		if(stat(token, &st) != 0 && value == NULL)
			break;
		token = strtok(NULL, ":\n");
	}
	printf("%s: %d: %s: not found\n", av, count, path);
	return(NULL);
}
/**
 * _error - Write a message in the standard error output
 * @msg: Message that should be displayed
 **/
void _error(char *msg)
{
	write(2, msg, _strlen(msg));
}
