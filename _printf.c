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
	char argument_char;
	char *argument_string;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			counter += percentage(percentage_pointer, format[i]);
		}
		else if (format[i] == 'c' && *percentage_pointer == 1)
		{
			argument_char = va_arg(ap, int);
			put_char(argument_char);
			counter++;
		}
		else if (format[i] == 's' && *percentage_pointer == 1)
		{
			argument_string = va_arg(ap, char *);
			counter += _printf(argument_string);
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
