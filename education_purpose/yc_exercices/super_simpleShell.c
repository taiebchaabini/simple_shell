#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	int i = 0;
	char *string;
	char *argv[] = {NULL};
	char *token;
	pid_t chproc;
	size_t buffer_size = 64;
	size_t buffer;

	string = malloc(sizeof(char) * buffer_size + 1);
	if (string == NULL)
	{
		perror("no arguments entered");
		exit(-1);
	}
	printf("#cisfun$ ");
	while ((buffer = getline(&string, &buffer_size, stdin) != -1))
	{
		token = strtok(string, " \n");
		while (token != NULL)
		{
			argv[i] = strdup(token);
			token = strtok(NULL, " \n");
			i++;
		}
		chproc = fork();
		if (chproc == -1)
		{
			perror("failed");
			exit(-1);
		}
		if (chproc == 0)
		{
			execve(argv[0], argv + 1, NULL);
		}
		wait(0);
		printf("#cisfun$ ");
		free(string);
	}
	exit(1);
}
