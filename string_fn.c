#include "simple.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
**/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - Function that prints a string like a puts function
 * @str: pointer to char
 * @bs : if bs 1 end string with \n otherwise not
 **/
void _puts(char *str, int bs)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	if (bs == 1)
		_putchar('\n');
}
/**
 * _strlen - Function that returns the length of a string
 * @s: pointer to char
 * Return: Always return length of @s
 **/
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * str_concat - function that concatenates two strings.
 * @s1: pointer of char
 * @s2: pointer of char
 * Return: two strings concatenated
 **/
char *str_concat(const char *s1, const char *s2)
{
	unsigned int i = 0, b = 0, c = 0, d = 0;
	char *p;

	if (s1 != NULL)
	{
		for (i = 0; s1[i] != '\0'; i++)
			;
	}
	if (s2 != NULL)
	{
		for (b = 0; s2[b] != '\0'; b++)
			;
	}
	p = malloc((i + b + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (c = 0; c < i; c++)
		p[c] = s1[c];
	for (d = 0; d < b; d++)
		p[c + d] = s2[d];
	p[(c + d) + 1] = '\0';
	return (p);
}
/**
 * _strcmp - Function that compares two strings
 * @s1: pointer to char
 * @s2: pointer to char
 * Return: It return the dest value
 **/
int _strcmp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	return (*s1 - *s2);
}

