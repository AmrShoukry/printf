#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * rev_string - a function that returns a reversed string.
 * @s: The string to reverse.
 *
 * Return: a reversed version of @s, or NULL if allocation fails
 */

char *rev_string(char *s)
{
	int len = get_string_length(s);
	char *rev = malloc((len + 1) * sizeof(char));
	int i;

	if (rev == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for reversed string.\n");
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		rev[i] = s[len - i - 1];
	}

	rev[len] = '\0';

	return (rev);
}
