#include "main.h"

/**
 * adjust_flags - Entry point
 *
 * @flags: flags
 * @specifier: character
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


void adjust_flags(int *flags, char specifier)
{
	int i;

	if (flags[0] == 1)
	{
		flags[1] = 0;
	}
	if (flags[1] == 1)
	{
		flags[0] = 0;
	}
	if (flags[2] == 1)
	{
		flags[4] = 0;
	}
	if (!(specifier == 'x' || specifier == 'X'))
	{
		flags[3] = 0;
	}
	if (specifier == 's' || specifier == 'c' || specifier == 'p')
	{
		for (i = 0; i <= 6; i++)
		{
			if (i == 2 || i == 5)
			{
				continue;
			}
			flags[i] = 0;
		}
	}
	if (specifier == 'r' || specifier == 'R' || specifier == 'S')
	{
		for (i = 0; i <= 6; i++)
		{
			flags[i] = 0;
		}
	}
}
