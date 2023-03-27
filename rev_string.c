#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * rev_string - Reverses a string using malloc
 * @s: The string to reverse
 */

void rev_string(char *s)
{
	int len = strlen(s);
	char *temp = malloc(sizeof(char) * len);

	if (!temp)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return;
	}

	memcpy(temp, s, len);

	for (int i = 0; i < len; i++)
	{
		s[i] = temp[len - i - 1];
	}
	free(temp);
}
