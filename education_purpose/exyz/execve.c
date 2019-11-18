#include <stdio.h>
#include <unistd.h>
/**
  works just fine only problem it does not run all command for example
  type vim and it would give you error i think it is related to the second
  argument of execve
 */
int main(int argc, char *argv[])
{
    printf("Before execve\n");
    if (argc == 2)
    {
	    if (execve(argv[1], argv, NULL) == -1)
		    puts("try again");
    }
    else
	    puts("too many arguments");
}
