#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


int main(void)
{
	put_char('A');
	put_char('\n');
	
	int number = 90;
	int base = 16;
	int len = get_base_length(number, base);
	printf("Length: of number: %i of base %i is %i\n", number, base, len);

	char *str = (char *) malloc (sizeof(char) * (len + 1));
	add_null_terminator(str, len);
	char *numberString = convert_decimal_to_base_string(number, len, base, str);
	
	printf("Number in octal is: %s\n", numberString);

	return (0);
}
