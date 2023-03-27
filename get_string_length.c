#include "main.h"
#include <stdio.h>

/**
 * get_string_length - a functions that returns the length of a string.
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
