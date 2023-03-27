#include "main.h"

/**
 * assign_flag - Entry point
 *
 * @flags: array
 * @flag: char
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


void assign_flag(int *flags, char flag)
{
	if (flag == ' ')
	{
		flags[0] = 1;
	}
	else if (flag == '+')
	{
		flags[1] = 1;
	}
	else if (flag == '-')
	{
		flags[2] = 1;
	}
	else if (flag == '#')
	{
		flags[3] = 1;
	}
	else if (flag == '0')
	{
		flags[4] = 1;
	}
	else if (flag == ' ')
	{

	}
	else if (flag == 'l')
	{
		flags[6] = 1;
	}
	else if (flag == 'h')
	{
		flags[6] = 2;
	}

}
