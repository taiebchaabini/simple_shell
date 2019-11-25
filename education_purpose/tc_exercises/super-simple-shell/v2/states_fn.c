#include "simple.h"
/**
 * _checkstat - function to check if file / directory exist
 * @argv0: filename to check
 * @st: buffer
**/
void _which(const char *path, struct stat *buf)
{
	struct stat st;

	if (path == NULL || buf == NULL)
	{
		perror("stat args");
	}
	if (stat(path, &st) == -1)
	{
		perror(path);
	}
}
