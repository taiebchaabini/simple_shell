#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
  *main - print delimited tokens of a given string 
  *the program won't get out after execution
  *works well with supersimple shell
  */
int main()
{
	char *string;
	char *token;
	size_t buffer_size = 64;
	size_t buffer;

	string = malloc(sizeof(char) * buffer_size + 1);
	if (string == NULL)
	{
		perror("no arguments entered");
		exit(-1);
	}
	printf("#cisfun$ ");
	while ((buffer = getline(&string, &buffer_size, stdin)) != -1 )
	{
		token = strtok(string, " \n");
		while (token != NULL)
		{
			printf("%s \n", token);
			token = strtok(NULL, " \n");
		}
		printf("#cisfun$ ");
	}
	free(string);
	exit(0);
}
