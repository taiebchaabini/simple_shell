#include "simple.h"
/**
 * main - Simple shell
 * @ac: number of argument passed to function
 * @av: arguments passed to the program
 * @env: environment of the program
 * Return: exit(EXIT_SUCCESS) otherwise exit(-1)
 **/
int main(__attribute__ ((unused)) int ac, char *av[], char **env)
{
	pid_t children_pid;
	char *line = NULL, *str = NULL, **argv = NULL;
	ssize_t read = 0, errve = 0;
	size_t len = 0, count = 0, i = 0;
	struct stat st;

	signal(SIGINT, signalHandler);
	_shsign();
	for (i = 0 ; (read = getline(&line, &len, stdin)) != -1; )
	{
		while (line[i] != '\0' && (line[i] == '\n' || line[i] == ' '))
			i++;
		if (line[i] != '\0' && line[i] != '\n')
		{
			str = _calloc(_strlen(line), sizeof(line));
			str = _strdup(line);
			if (str == NULL)
				exit(0);
			argv = _getsubtoken(str, " \n");
			argv[0] = _which(argv[0], &st, count, av[0]);
		}
		else
			argv[0] = "";
		children_pid = fork();
		if (children_pid == 0)
			errve = execve(argv[0], argv, env);
		if (errve == -1)
			exit(0);
		count++;
		wait(0);
		_shsign();
	}
	isatty(STDIN_FILENO) ? _puts("\n", 0) : exit(EXIT_SUCCESS);
	return (0);
}
