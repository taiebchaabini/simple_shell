#include "exercises/simple.h"
/**
* main - My super simple shell #v0
**/
int main(void)
{
	int state = 0;
	pid_t children_pid;
	ssize_t read;
	size_t len;
	char *line = NULL, *str = NULL, *token = NULL;
	char *argv[] = {NULL};
	int i = 0;

	shsign
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		children_pid = fork();
		str = malloc(sizeof(char) * strlen(line));
		if (str == NULL)
			exit(-1);
		*argv = malloc(sizeof(char) * strlen(line));
		if (argv == NULL)
			exit(-1);
		str = strcpy(str, line);
		token = strtok(str, delim);
		while (token != NULL)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			if(argv[i] == NULL)
				exit(-1);
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;
		if (children_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
			shsign
			wait(0);
	}
	free(line);
	exit(EXIT_SUCCESS);
}
