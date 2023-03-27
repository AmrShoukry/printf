#include "main.h"

/**
 * get_base_length - Entry point
 *
 * @decimal: number
 * @base: base
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


int get_base_length(int decimal, int base)
{
	int counter = -1;

	if (decimal > 0)
	{
		counter = get_base_length(decimal / base, base);
	}
	counter++;
	return (counter);
}
