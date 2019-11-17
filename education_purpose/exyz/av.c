#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*mainey*/
int main(int ac, char **av)
{
	int i;
	for(i = 1; av[i] != '\0'; i++)
		printf(" %s", av[i]);
	printf("\n");
	return (0);
}
