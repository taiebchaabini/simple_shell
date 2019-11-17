#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *string;
	size_t size = 64;
	size_t buffer;

	printf("$ ");
	string = malloc(sizeof(char) * size + 1);
	buffer = getline(&string, &size, stdin);
	if (buffer == -1)
		puts("error");
	else
	{
		printf("%s", string);
		return (0);
	}
}
