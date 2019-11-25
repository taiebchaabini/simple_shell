#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//3.PATH prints path environment variable
int main(void)
{
	printf("%s \n", getenv("PATH"));
}
