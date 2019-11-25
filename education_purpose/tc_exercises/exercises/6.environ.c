#include <unistd.h>
#include <stdio.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i;
	extern char **environ;

	i = 0;
	printf("Adress of environ is : %p \n", environ);
	printf("Adress of env is : %p\n", env);
	return (0);
}
