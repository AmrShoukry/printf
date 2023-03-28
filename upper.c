#include "main.h"
#include <stdlib.h>

/**
 * upper - Entry point
 *
 * @string: char
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


char *upper(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] >= 97 && string[i] <= 122)
		{
			string[i] = string[i] - 32;
		}
	}

	return (string);
}
