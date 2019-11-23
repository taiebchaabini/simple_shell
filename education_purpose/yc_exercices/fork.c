#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
  *main - a simple fork program excute and wait program
  *NOTE:  it works fine
  */
int main()
{
	pid_t chpid;
	int status, i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	while (i < 5)
	{
		chpid = fork();
		if (chpid < 0)
		{
			perror("error");
			exit(-1);
		}
		if (chpid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
