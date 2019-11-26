#include "simple.h"
/**
 * main - My super simple shell #v0
 * Return: exit(EXIT_SUCCESS) otherwise exit(-1)
**/
int main(void)
{
	int state = 0;
	pid_t children_pid;
	ssize_t read;
	size_t len;
	char *line = NULL, *str = NULL, *token = NULL, *argv[] = {NULL};
	int i = 0, count = 0;
	struct stat st;

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
		argv[0] = _which(argv[0], &st, count);
		children_pid = fork();
		if (children_pid == 0)
			execve(argv[0], argv, NULL);
		count++;
		wait(0);
		_puts("#cisfun$ ", 0);
	}
	exit(EXIT_SUCCESS);
}
