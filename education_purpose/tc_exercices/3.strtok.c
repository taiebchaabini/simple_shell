#include "simple.h"
/**
* main - sample program, try to use , to delimit a string
* @ac: number of args
* @av: arguments passed to the program
* Return (EXIT_SUCCESS) if success otherwise -1
**/
int main(void)
{
	size_t len = 0;
	ssize_t read;
	char *buf = NULL;
	char *strtmp = NULL;
	char *token = NULL;
	char *delim = " ";

	buf = malloc(sizeof(size_t));
	if (buf == NULL)
		exit(-1);

	shsign
	while ((read = getline(&buf, &len, stdin)) != -1)
	{
		strtmp = malloc(sizeof(char) * strlen(buf));
		if (strtmp == NULL)
			return (-1);
		strtmp = strcpy(strtmp, buf);
		token = strtok(strtmp, delim);
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, delim);
		}
		break;
		shsign
	}
	free(buf);
	exit(EXIT_SUCCESS);
}
