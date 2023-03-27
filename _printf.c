#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

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
	int percentage_mode = 0;
	int slash_mode = 0;
	int numbers_mode = 0;
	int number_result = 0;
	int counter = 0;
	int i = 0;
	int lc;
	int base;
	int argument_length;
	int flags[] = {0, 0, 0, 0, 0, 0, 0};
	char argument_char;
	int argument_int;
	char *argument_string;
	void *argument_pointer;
	char *temporary_string;
	va_list ap;

	va_start(ap, format);

	while (format[i] != '\0')
	{
		switch (format[i])
		{
			case '%':
				if (slash_mode == 0 && percentage_mode == 0)
				{
					percentage_mode = 1;
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case '\\':
				printf("7");
				if (percentage_mode == 1)
				{
					continue;
				}
				else if (slash_mode == 0)
				{
					slash_mode = 1;
				}
				else
				{
					put_char(format[i]);
					counter++;
					slash_mode = 0;
				}
				break;

			case '"':
				if (slash_mode == 1)
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case '\'':
				if (percentage_mode == 1)
				{
					continue;
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;
/*
			case 'n':
				if (percentage_mode == 1)
				{
					continue;
				}
				else if (slash_mode == 1)
				{
					put_char('\n');
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;
*/
			case ' ':
			case '+':
			case '-':
			case '#':
			case 'l':
			case 'h':
				if (percentage_mode == 1)
				{
					assign_flag(flags, format[i]);
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case '0':
				if (percentage_mode == 1 && numbers_mode == 0)
				{
					assign_flag(flags, format[i]);
				}
				else if (numbers_mode == 1)
				{
					number_result = number_result * 10;
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case 'c':
				numbers_mode = 0;
				if (percentage_mode == 1)
				{
					percentage_mode = 0;
					flags[5] = number_result;
					argument_char = va_arg(ap, int);
					put_char(argument_char);
					counter++;
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case 's':
				numbers_mode = 0;
				if (percentage_mode == 1)
				{
					percentage_mode = 0;
					flags[5] = number_result;
					temporary_string = va_arg(ap, char *);
					counter += specifier_s(flags, temporary_string);
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case 'i':
			case 'd':
			case 'b':
			case 'x':
			case 'X':
			case 'o':
				numbers_mode = 0;
				if (percentage_mode == 1)
				{
					if (format[i] == 'x' || format[i] == 'X')
					{
						base = 16;
					}
					else if (format[i] == 'o')
					{
						base = 8;
					}
					else if (format[i] == 'b')
					{
						base = 2;
					}
					else
					{
						base = 10;
					}
					percentage_mode = 0;
					flags[5] = number_result;
					argument_int = va_arg(ap, int);
					argument_length = get_base_length(argument_int, base);
					argument_string = (char *) malloc(sizeof(char) * (argument_length + 1));
					temporary_string = convert_decimal_to_base_string(argument_int, argument_length, base, argument_string);
					counter += _printf(temporary_string);
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case 'p':
				numbers_mode = 0;
				if (percentage_mode == 1)
				{
					percentage_mode = 0;
					flags[5] = number_result;
					argument_pointer = va_arg(ap, void *);
					temporary_string = convert_address_to_string(argument_pointer);
					counter += _printf(temporary_string);
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			case 'S':
			case 'r':
			case 'R':
				numbers_mode = 0;
				if (percentage_mode == 1)
				{
					percentage_mode = 0;
					flags[5] = number_result;
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
				break;

			default:
				if (format[i] >= '0' && format[i] <= '9')
				{
					if (percentage_mode == 1 && numbers_mode == 1)
					{
						number_result = (number_result * 10) + format[i] + 48;
					}
					else
					{
						put_char(format[i]);
						counter++;
					}
				}
				else
				{
					put_char(format[i]);
					counter++;
				}
		}
		i++;
	}

	va_end(ap);

	return (counter);
}
