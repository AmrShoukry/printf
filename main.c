#include <limits.h>
#include <stdio.h>
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
	int base = 8;
	int len = get_base_length(number, base);
	printf("Length: of number: %i of base %i is %i\n", number, base, len);

	return (0);
}
