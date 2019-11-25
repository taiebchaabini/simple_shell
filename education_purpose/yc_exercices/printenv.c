#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main (int argc, char **argv, char **envp)
{
	int i;
	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
