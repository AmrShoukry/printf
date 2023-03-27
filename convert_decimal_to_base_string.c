#include "main.h"

/**
 * convert_decimal_to_base_string - Entry point
 *
 * @decimal: character
 * @len: int
 * @base: int
 * @str: string
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


char *convert_decimal_to_base_string(int decimal, int len, int base, char *str)
{
	int remainder;

	if (decimal > 0)
	{
		remainder = decimal % base;

		if (remainder >= 10)
		{
			str[len - 1] = remainder + 87;
		}
		else
		{
			str[len - 1] = remainder + 48;
		}

		convert_decimal_to_base_string(decimal / base, len - 1, base, str);
	}

	return (str);
}
