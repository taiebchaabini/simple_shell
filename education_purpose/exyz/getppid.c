#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/*getppid of process*/
int main()
{
	int l, sum = 0;

	sum = 4 *4;
	l = getppid();
	printf("the damned PPID is %d\n", l);
}

