#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *string;
	size_t size = 64;
	size_t buffer;

	string = malloc(sizeof(size_t) * size + 1);
	if (string == NULL)
		exit(EXIT_FAILURE);
	printf("$ ");
	while((buffer = getline(&string, &size, stdin)) != -1)
	{
		printf("%s", string);
		printf("$ ");
	}
	free(string); //free 

	exit(EXIT_SUCCESS);
}
