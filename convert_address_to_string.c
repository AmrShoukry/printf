#include "main.h"
#include <stdlib.h>

/**
 * convert_address_to_string - Entry point
 *
 * @ptr: address
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */



char *convert_address_to_string(void *ptr)
{
	unsigned long address = (unsigned long)ptr;
	int shift = sizeof(address)*8 - 4;
	int i, first_digit_found = 0;
	int counter = 0;
	char *result =(char *) malloc(16 * 1);
	int digit;

	counter++;
	counter++;
	result[0] = '0';
	result[1] = 'x';

	for (i = 0; i < sizeof(address)*2; i++)
	{
		digit = (address >> shift) & 0xf;
		if (digit != 0 || first_digit_found)
		{
			first_digit_found = 1;
			result[counter] = "0123456789abcdef"[digit];
			counter++;
		}
		shift -= 4;
	}

	if (!first_digit_found)
	{
		result[2] = 0;
		counter++;
	}

	result[counter] = '\0';

	return (result);
}
