#include "simple.h"
/**
 * _strdup -  function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter.
 * @str: pointer of char
 * Return: return pointer if allocated memory success otherwise NULL
**/
char *_strdup(const char *str)
{
	unsigned int i = 0, b = 0;
	char *p;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	p = malloc(i + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (b = 0; b < i; b++)
		p[b] = str[b];
	p[b + 1] = '\0';
	return (p);
}
