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
/**
 * _calloc - function that allocates memory for an array, using malloc.
 * @nmemb: number of elements
 * @size: size of type
 i * Return: pointer
 **/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
		exit(-1);
	p = malloc((nmemb + 1) * size);
	if (p == NULL)
	{
		perror(p);
		exit(-1);
	}
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
/**
 * free_grid - function that frees a 2 dimensional grid previously created by
 * your alloc_grid function.
 * @grid: the address of the two dimensional grid
 * @height: height of the grid
**/
void free_grid(int **grid, int height)
{
	int h = 0;

	for (; h < height; h++)
	{
		free(grid[h]);
	}
	free(grid);
}
