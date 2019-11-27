#include "simple.h"
/**
 * main - Simple shell
 * Return: exit(EXIT_SUCCESS) otherwise exit(-1)
**/
int main(int ac, char *av[])
{
	int state = 0;
	pid_t children_pid;
	ssize_t read;
	size_t len;
	char *line = NULL, *str = NULL, *token = NULL, *argv[] = {NULL};
	int i = 0, count = 0, errve = 0;
	struct stat st;

	/*
	char *tmp = NULL;
	tmp = str_concat(":", _getenv("PATH"));
	_setenv("PATH", tmp, 0);
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	i = 0;
	*/
	_puts("#cisfun$ ", 0);
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		str = malloc(sizeof(char) * _strlen(line));
		if (str == NULL)
			exit(-1);
		*argv = NULL;
		*argv = malloc(sizeof(char) * _strlen(line));
		if (argv == NULL)
			exit(-1);
		str = strcpy(str, line);
		token = strtok(str, delim);
		i = 0;
		while (token != NULL)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			if (argv[i] == NULL)
				exit(-1);
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;
		if (_strcmp(argv[0], "exit") == 0)
				exit(0);
		argv[0] = _which(argv[0], &st, count, av[0]);
		children_pid = fork();
		if (children_pid == 0)
			errve = execve(argv[0], argv, NULL);
		if (errve == -1)
			exit(0);
		count++;
		wait(0);
		_puts("#cisfun$ ", 0);
	}
	exit(EXIT_SUCCESS);
}
