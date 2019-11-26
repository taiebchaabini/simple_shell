#ifndef simple_h
#define simple_h
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define shsign printf("#cisfun$ ")
#define delim " \n"
extern char **environ;
/** string_fn.c **/
int _strlen(char *s);
char *str_concat(const char *s1, const char *s2);
/** states_fn.c **/
char *_which(const char *path, struct stat *buf, int count);
/** env_fn.c **/
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
#endif
