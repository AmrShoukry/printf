#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * percentage - Entry point
 *
 * @percentage_ptr: text
 * @c: char
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */

int percentage(int *percentage_ptr, char c)
{
	if (c == '%')
	{
		if (*percentage_ptr == 0)
		{
			*percentage_ptr = 1;
			return (0);
		}
		else
		{
			put_char(c);
			return (1);
		}
	}
	else
	{
		return (0);
	}
}


/**
 * _printf - Entry point
 *
 * @format: text
 *
 * Description: 'Main function is used to print alphabets'
 *
 * Return: Always 0 (Success)
 */


int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;
	int percentage_mode = 0;
	int counter = 0;
	int *percentage_pointer = &percentage_mode;
	int arg_int, length;
	char *temp;
	char *string;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			counter += percentage(percentage_pointer, format[i]);
		}
		else if ((format[i] == 'd' || format[i] == 'i') && *percentage_pointer == 1)
		{
			arg_int = va_arg(ap, int);
			length = get_base_length(arg_int, 10);
			temp = (char *) malloc(sizeof(char) * (length + 1));
			string = convert_decimal_to_base_string(arg_int, length, 10, temp);
			counter += _printf(string);
		}
		else
		{
			put_char(format[i]);
			counter++;
		}
		i++;
	}

	va_end(ap);

	return (counter);
}
