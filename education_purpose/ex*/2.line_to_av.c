#include "simple.h"
/**
* main - sample program, try to use , to delimit a string
* @ac: number of args
* @av: arguments passed to the program
* Return (EXIT_SUCCESS) if success otherwise -1
**/
int main(int ac, char **av)
{
	size_t len = 0;
	ssize_t read;
	char *buf = NULL;

	buf = malloc(sizeof(size_t));
	if (buf == NULL)
		exit(-1);

	shsign
	while ((read = getline(&buf, &len, stdin)) != -1)
	{
		printf("%s", strtok(buf, ","));
		shsign
	}
	free(buf);
	exit(EXIT_SUCCESS);
}
