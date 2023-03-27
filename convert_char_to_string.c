#include "main.h"
#include <stdlib.h>

/**
 * convert_char_to_string - Entry point
 *
 * @character: char
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


char *convert_char_to_string(char character)
{
	char *string = (char *) malloc(sizeof(char) * 2);
	string[0] = character;
	string[1] = '\0';

	return (string);
}
