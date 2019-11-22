#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("My parent pid is %u\n", getppid());
	printf("Before fork\n\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid >= 0)
	{
	printf("\nAfter fork PID IS = %u \n", pid);
	my_pid = getpid();
	printf("My pid is %u\n", getpid());
	printf("My parent pid is %u\n", getppid());
	wait(0);
	}
	return (0);
}
