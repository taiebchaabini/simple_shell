#ifndef simple_h
#define simple_h
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define shsign printf("#cisfun$ ");
#define delim " \n"
struct stat *buf;
int _strlen(char *s);
void _checkstat(const char *path, struct stat *buf);
#endif
