#include "main.h"
#include <stdlib.h>

/**
 * fill_length - Entry point
 *
 * @character: char
 * @length: length
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


void fill_length(char character, int length)
{
	int i = 0;

	for (i = 0; i < length; i++)
	{
		put_char(character);
	}
}
