#include "main.h"

/**
 * fill_string - Entry point
 *
 * @flags: flags
 * @specifier: character
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


char *fill_string(int sp, int pos, char dir, int hash, char fill, int fill_len, int length)
{
	int counter = 0;
	int buffer = fill_len - length;
	char *string;

	if (hash == 1)
	{
		counter += 2;
	}
	if (pos == 1 || sp == 1)
	{
		counter++;
	}
	if (buffer > 0)
	{
		counter += buffer;
	}

	string = (char *) malloc(sizeof(char) * (counter + 1));

	if (dir == 'l')
	{

	}
	else if (dir == 'r')
	{
		
	}
	
}
