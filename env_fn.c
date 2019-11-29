#include "simple.h"
/**
 * _getenv - function that gets an environment variable.
 * @name: name of the environment variable we are looking for.
 * Return: pointer to env otherwise NULL.
 **/
char *_getenv(const char *name)
{
	int i = 0;
	char *str = NULL, *token = NULL;

	if (name == NULL)
	{
		_puts("_getenv : no argument passed", 0);
		exit(-1);
	}
	while (environ[i] != NULL)
	{
		str = _calloc(_strlen(environ[i]), sizeof(char));
		str = _strdup(environ[i]);
		token = _calloc(_strlen(str), sizeof(char));
		token = strtok(str, "=\n");
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=\n");
			return (token);
		}
		i++;
	}
	return (NULL);
}
/**
 * _setenv - function that changes or adds an environment variable
 * @name: environment variable name to change or add
 * @value: environment value to change or add
 * Return: return 0 on success or -1 on error
 **/
int _setenv(const char *name, const char *value)
{
	int i = 0;
	char *env = NULL, *newval = NULL, *str = NULL;

	env = _getenv(name);
	while (environ[i] != NULL)
	{
		str = _strdup(environ[i]);
		str = strtok(str, "=");
		if (_strcmp(str, name) == 0)
			break;
		i++;
	}
	newval = malloc(sizeof(char) * ((_strlen(name) + _strlen(value)) + 1));
	if (newval == NULL)
		exit(-1);
	newval = str_concat(str_concat(name, "="), value);
	if (env == NULL || environ[i] == NULL)
		environ[i + 1] = NULL;
	environ[i] = malloc(sizeof(char) * ((_strlen(name) + _strlen(value)) + 1));
	environ[i] = newval;
	return (0);
}
/**
 * _unsetenv - function that deletes the variable name from the environment
 * @name: name of environment variable we need to delete
 * Return: 0 if success otherwise -1 if error
 **/
int _unsetenv(const char *name)
{
	int i = 0;
	char *str = NULL;

	while (environ[i] != NULL)
	{
		str = _strdup(environ[i]);
		str = strtok(str, "=");
		if (_strcmp(str, name) == 0)
			break;
		i++;
	}
	if (environ[i] != NULL)
	{
		if (environ[i + 1] == NULL)
			environ[i] = NULL;
		while (environ[i] != NULL)
		{
			environ[i] = environ[i + 1];
			i++;
		}
		return (0);
	}
	return (-1);
}
/**
  * signalHandler - Handling control + c
  * @sig: take an integer as param
**/
void signalHandler(int sig)
{

	write(STDOUT_FILENO, "\n($)", 4);
}
