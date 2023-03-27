#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_string_length - a function that returns the length of a string.
 * @string: The string to get its length.
 *
 * Return: the length of @string
 */

int get_string_length(char *string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	return (length);
}

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

	if (rev == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for reversed string.\n");
		return (NULL);
	}

	for (int i = 0; i < len; i++)
	{
		rev[i] = s[len - i - 1];
	}

	rev[len] = '\0';

	return (rev);
}
