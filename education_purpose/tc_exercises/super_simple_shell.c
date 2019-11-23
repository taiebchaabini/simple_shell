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
	char *line = NULL;
	const char *argv[];

	shsign
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		children_pid = fork();
		if (children_pid == -1)
		{
			perror("ERROR WHILE CREATING CHILD PROCESS");
			exit(-1);
		}
		else if(children_pid >= 0)
		{
			argv = malloc(sizeof(char) * strlen(line));
			argv[0] = &line
			printf("%s", argv[0]);
			execve(line[0], line, NULL);
			wait(&state);
		}
		shsign
	}
	free(line);
	exit(EXIT_SUCCESS);
}
