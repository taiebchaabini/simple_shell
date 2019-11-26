#include "simple.h"
/**
* _getenv - function that gets an environment variable.
* @name: name of the environment variable we are looking for.
* Return: pointer to env otherwise NULL.
**/
char *_getenv(const char *name)
{
	int i = 0;
	char *str = NULL;
	char *token = NULL;

	while (environ[i] != NULL)
	{
		str = malloc(sizeof(char) * strlen(environ[i]));
		str = strcpy(str, environ[i]);
		token = malloc(sizeof(char) * strlen(str));
		token = strtok(str, "=\n");
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=\n");
			return (token);
		}
		i++;
	}
	printf("ERROR\n");
	return (NULL);
}
