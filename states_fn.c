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
		printf("_which (ERROR) : PATH or BUF is NULL");
	}
	value = _getenv("PATH");
	token = malloc(sizeof(char) * strlen(value));
	if (token == NULL)
	{
		perror("getenvdir: malloc problem");
		exit(-1);
	}
	token = strtok(value, ":\n");
	pathtemp = strdup(path);
	while (token != NULL)
	{
		if (stat(pathtemp, &st) == 0)
			return (pathtemp);
		token = str_concat(str_concat(token, "/"), path);
		if (stat(token, &st) == 0)
			return (token);
		token = strtok(NULL, ":\n");
	}
	printf("%s: %d: %s: not found\n", _getenv("_"), count, path);
	return (NULL);
}
