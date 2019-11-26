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
	char *str;
	pid_t chproc;
	size_t buffer_size;
	size_t buffer;
	
	printf("#cisfun$ ");
	while ((buffer = getline(&string, &buffer_size, stdin) != -1))
	{
		str = malloc(sizeof(char) * strlen(string));
		if (str == NULL)
			return (-1);
		*argv = malloc(sizeof(char) * strlen(string));
		if (argv == NULL)
			return (-1);
		str = strdup(string);
		token = strtok(str, " \n");
		i = 0;
		while (token != NULL)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			if (argv[i] == NULL)
				return (-1);
			argv[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		argv[i] = NULL;
		execve(argv[0], argv, NULL);
		printf("#cisfun$ ");
	}
	exit(1);
}
