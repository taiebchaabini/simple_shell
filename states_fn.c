#include "simple.h"
/**
 * _which - function to check if the program exist in PATH directories
 * @argv0: filename to check
 * @st: buffer
 **/
char *_which(const char *path, struct stat *buf, int count)
{
	struct stat st;
	int i = 0;
	char *value = NULL, *token = NULL;
	char *state = NULL, *pathtemp = NULL;

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
		perror(token);
		exit(-1);
	}
	if(value[0] == ':')
	{
		_error("cisfun\n");
		return (NULL);
	}
	token = strtok(value, ":\n");
	}
	pathtemp = _strdup(path);
	while (token != NULL || value == NULL)
	{
		if (stat(path, &st) == 0 || stat(path, &st) == 0 && value == NULL)
			return (pathtemp);
		//pathtemp = strtok(pathtemp, " \n");
		token = str_concat(str_concat(token, "/"), path);
		if (stat(token, &st) == 0)
			return (token);
		if(stat(token, &st) != 0 && value == NULL)
			break;
		token = strtok(NULL, ":\n");
	}
	_getenv("_");
	printf("%s: %d: %s: not found\n", _getenv("_"), count, path);
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
