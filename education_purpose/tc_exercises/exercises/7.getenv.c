#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *_getenv(const char *name)
{
	int i = 0;
	extern char **environ;

	while (environ[i] != NULL)
	{
		if (environ[i] == name)
			return (environ[i]);
		environ++;
	}
	printf("_getenv : failed to find env.");
	return (NULL);
}

int main(int ac, char **ar)
{
	if (ac != 2)
	{
		printf("Only one argument allowed.");
		exit(0);
	}
	_getenv(ar[1]);
	exit(0);
}
