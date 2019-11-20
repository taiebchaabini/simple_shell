#include "simple.h"
/**
* main - sample program
* @ac: number of args
* @av: arguments passed to the program
* Return (EXIT_SUCCESS) if success otherwise -1
**/
#define shsign printf("$ ");
int main(void)
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
		printf("%s", buf);
		shsign
	}
	free(buf);
	exit(EXIT_SUCCESS);
}
