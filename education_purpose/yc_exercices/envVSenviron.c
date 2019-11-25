#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//same as printenv using main argument env
int main(int argc, char **argv, char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
		printf("%s\n", envp[i]);
}
