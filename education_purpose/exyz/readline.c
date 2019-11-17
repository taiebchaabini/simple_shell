#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *string;
	size_t size = 64;
	size_t buffer;

	printf("$ ");
	string = malloc(sizeof(size_t) * size + 1);
	if (string == NULL)
		exit(-1);
	while((buffer = getline(&string, &size, stdin)) != -1)
	{
		printf("%s", string);
		shsing //in place of printf and shows $ sign
	}
	free(buffer); //free 

	exit(EXIT_SUCCESS);
}
