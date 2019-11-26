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
		printf("_getenv : no argument passed\n");
		exit(-1);
	}
	while (environ[i] != NULL)
	{
		str = malloc(sizeof(char) * strlen(environ[i]));
		if (str == NULL)
			return (NULL);
		str = strcpy(str, environ[i]);
		token = malloc(sizeof(char) * strlen(str));
		if (token == NULL)
			return (NULL);
		token = strtok(str, "=\n");
		if (strcmp(token, name) == 0)
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
 * @overwrite: if overwrite is nonzero then the name is changed
 * Return: return 0 on success or -1 on error
 **/
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0;
	char *env = NULL, *newval = NULL, *str = NULL;

	env = _getenv(name);
	while (environ[i] != NULL)
	{
		str = strdup(environ[i]);
		str = strtok(str, "=");
		if (strcmp(str, name) == 0)
			break;
		i++;
	}
	newval = malloc(sizeof(char) * ((strlen(name) + strlen(value)) + 2));
	if (newval == NULL)
		exit(-1);
	newval = str_concat(str_concat(name, "="), value);
	if (env == NULL || environ[i] == NULL)
		environ[i + 1] = NULL;
	environ[i] = malloc(sizeof(char) * ((strlen(name) + strlen(value)) + 2));
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
		str = strdup(environ[i]);
		str = strtok(str, "=");
		if (strcmp(str, name) == 0)
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