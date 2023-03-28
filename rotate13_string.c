#include "main.h"
#include <stdlib.h>

/**
 * rotate13_string - Entry point
 *
 * @string: st
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


char *rotate13_string(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if ((string[i] >= 65 && string[i] <= 77) || (string[i] >= 97 && string[i] <= 109))
		{
			string[i] = string[i] + 13;
		}
		else if ((string[i] >= 78 && string[i] <= 90) || (string[i] >= 110 && string[i] <= 122))
		{
			string[i] = string[i] - 13;
		}
	}

	return (string);
}
