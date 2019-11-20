#include <stdio.h>
#include <unistd.h>
/*works just fine just if you want to run any process you need to type its directory and add options like example in the arguments section very cool hein
 */
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
    printf("%zu", getpid);//checks pid of process
//you can change argv + 1 with &argv[1] it works fine too
	    if (execve(argv[1], argv + 1, NULL) == -1)
		    puts("try again");
    }
    else
	    puts("fix you arguments count");
    getpid = getpid();
}
