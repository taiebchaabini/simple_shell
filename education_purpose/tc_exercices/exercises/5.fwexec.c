#include "simple.h"
int main(void)
{
	int i = 0, status;
	pid_t c_pid;
	char *argv[] = { "/bin/ls", "-l", "/tmp", NULL };

	while (i < 5)
	{
		c_pid = fork();
		if (c_pid == -1)
		{
			printf("ERROR");
			return (1);
		}
		else if (c_pid == 0)
		{
			printf("PID : %u | PARENT ID : %u \n", getpid(), getppid());
			execve(argv[0], argv, NULL);
		}
		if (wait(&status))
			i++;
	}
}
