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
	char *env;
	char *newval;

	env = _getenv("Taieb");
	if (env == NULL)
	{
		while (environ[i] != NULL)
		{
				printf("%s\n", environ[i]);
				i++;
		}
		newval = malloc(sizeof(char) * ((strlen(name) + strlen(value)) + 1));
		if (newval == NULL)
		{
			printf("_setenv : malloc problem");
			exit(-1);
		}
		newval = str_concat(name, "=");
		newval = str_concat(newval, value);
		environ[i] = malloc(sizeof(char) * strlen(newval));
		environ[i] = newval;
		environ[i + 1] = NULL;
		// create the env variable 
	}
}

int main()
{
	_setenv("taieb", "/bin/ls", 0);
	exit(1);
}
