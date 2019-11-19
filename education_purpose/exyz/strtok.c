#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*strtok: string token
 Note this program includes the getline function as well
 */
int main(int ac, char **av)
{
	char *string;
	char *parts;
	size_t buffer_size = 64;
	size_t buffer;
//the if(av[0]) is just for later use to set argument like strtok if there is none
//also i still didn't get how to set it right yet hhh
	if(av[0])
	{
	string = malloc(sizeof(size_t) * buffer_size + 1);
	if (string == NULL)
		exit(EXIT_FAILURE);
	printf("$ ");
	buffer = getline(&string, &buffer_size, stdin);
	if (buffer == -1)
		exit(97);
	parts = strtok(string, " \n");
	while (parts != NULL)
	{
		printf("%s\n", parts);
		parts = strtok(NULL, " \n");
	}
	free(string);
	exit(EXIT_SUCCESS);
	}
	else
	{
		printf("please enter a command\n");
	}
}
