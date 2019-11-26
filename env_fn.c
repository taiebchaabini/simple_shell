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
 * _getenvdir - function that prints each directory contained in the the 
 * environment variable PATH, one directory per line.
 **/
void _getenvdir(void)
{
	int i = 0;
	char *value = NULL, *token = NULL;

	value = _getenv("PATH");
	token = malloc(sizeof(char) * strlen(value));
	if (token == NULL)
	{
		perror("getenvdir: malloc problem");
		exit(-1);
	}
	token = strtok(value, ":\n");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":\n");
	}
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
	char *env = NULL, *newval = NULL;

	env = _getenv(name);
	if (env == NULL)
	{
		while (environ[i] != NULL)
		i++;
	}
	
	newval = malloc(sizeof(char) * ((strlen(name) + strlen(value)) + 1));
	if (newval == NULL)
		exit(-1);
	newval = str_concat(str_concat(name, "="), value);
	if (env == NULL)
		environ[i + 1] = NULL;
		environ[i] = malloc(sizeof(char) * strlen(newval));
		environ[i] = newval;
		return(0);
	/*
	while (environ[i] != NULL)
	{
		if (environ[i] == name)
		{
			newval = malloc(sizeof(char) * ((strlen(name) + strlen(value)) + 1));
			if (newval == NULL)
				exit(-1);
			newval = str_concat(strconcat(name, "="
			environ[i] =
			newval = strdup(value);
		}
	}
	*/
	return (-1);
}

int main()
{
	_setenv("taieb", "/bin/ls", 0);
	printf("Print env taieb : %s\n", _getenv("taieb"));
	_setenv("taieb", "/bin/bash", 0);
	printf("Print env taieb : %s\n", _getenv("taieb"));
	exit(1);
}
