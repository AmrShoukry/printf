#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * specifier_s - Entry point
 *
 * @character: char
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


int specifier_s(int *flags, char *string)
{
	int counter = 0;
	int i;	

	int string_length = get_string_length(string);
	int buffer_length = flags[5];
	int spaces_length = buffer_length - string_length;

	if (flags[2] == 0)
	{
		if (spaces_length > 0)
		{
			fill_length(' ', spaces_length);
			counter += spaces_length;
		}
		counter += _printf(string);
	}
	else
	{			
		counter += _printf(string);
		if (spaces_length > 0)
		{
			counter += spaces_length;
			fill_length(' ', spaces_length);
		}
	}

	return (counter);
}
