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
	int i = 0, percentage_mode = 0, counter = 0, arg_int, length, base, numbers_mode, number_result = 0;
	int numberflag_length;
	int buffer_length;
	int *percentage_pointer = &percentage_mode;
	char *temp, *string;
	char char_argument;
	char fill_mode = ' ';
	char sign_mode = '\0';
	void *ptr;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			counter += percentage(percentage_pointer, format[i]);
		else if ((format[i] == 'd' || format[i] == 'i') && *percentage_pointer == 1)
		{
			arg_int = va_arg(ap, int);
			length = get_base_length(arg_int, 10);
			temp = (char *) malloc(sizeof(char) * (length + 1));
			string = convert_decimal_to_base_string(arg_int, length, 10, temp);
/*
			flags[5] = number_result;
			numbers_mode = 0;

			numberflag_length = flags[5];
			buffer_length = numberflag_length - length;

			if (flags[4] == 1)
			{
				fill_mode = '0';
			}
			else 
			{
				fill_mode = ' ';
			}

			if (arg_int >= 0)
			{
				if (flags[1] == 1)
				{
					sign_mode = '+';
					buffer_length--;
				}
				else if (flags[0] == 1)
				{
					sign_mode = ' ';
					buffer_length--;
				}
			}
			else
			{
				sign_mode = '\0';
			}

			if (fill_mode == '0' && flags[2] == 0 && buffer_length > 0)
			{
				putchar(sign_mode);
				counter += fill_length(fill_mode, buffer_length);
			}
			else if (fill_mode == ' ' && flags[2] == 0 && buffer_length > 0)
			{
				counter += fill_length(fill_mode, buffer_length);
				put_char(sign_mode);
			}
			else if (flags[2] == 1 && (flags[1] == 1 || flags[0] == 1))
			{
				put_char(sign_mode);
			}*/
			counter += _printf(string);
			percentage_mode = 0;
/*
			if (flags[2] == 1 && fill_mode == ' ' && buffer_length > 0)
			{
				counter += fill_length(fill_mode, buffer_length);
			}*/
		}
		else if (format[i] == 'c' && *percentage_pointer == 1)
		{
			char_argument = va_arg(ap, int);
			put_char(char_argument);
			counter++;
			percentage_mode = 0;
		}
		else if (format[i] == 's' && *percentage_pointer == 1)
		{
			string = va_arg(ap, char *);
			flags[5] = number_result;
			numbers_mode = 0;
			counter += _printf(string);
			percentage_mode = 0;
		}
		else if ((format[i] == 'b' || format[i] == 'o' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X') && *percentage_pointer == 1)
		{
			if (format[i] == 'b')
				base = 2;
			else if (format[i] == 'o')
				base = 8;
			else if (format[i] == 'u')
				base = 10;
			else if (format[i] == 'x' || format[i] == 'X')
			{
				base = 16;
				if (flags[3] == 1)
				{
					put_char('0');
					put(format[i]);
					counter += 2;
				}
			}
			arg_int = va_arg(ap, int);
			length = get_base_length(arg_int , base);
			temp = (char *) malloc(sizeof(char) * (length + 1));
			string = convert_decimal_to_base_string(arg_int, length, base, temp);
			if (format[i] == 'X')
			{
				string = upper(string);
			}
			counter += _printf(string);
			percentage_mode = 0;
		}
		else if (format[i] == 'p' && *percentage_pointer == 1)
		{
			ptr = va_arg(ap, void *);
			string = convert_address_to_string(ptr);
			counter += _printf(string);
			percentage_mode = 0;
		}
		else if (format[i] == 'R' && *percentage_pointer == 1)
		{
			temp = va_arg(ap, char *);
			string = rotate13_string(temp);
			counter += _printf(string);
			percentage_mode = 0;
		}
		else if (format[i] == 'r' && *percentage_pointer == 1)
		{
			temp = va_arg(ap, char *);
			string = reverse_string(temp);
			counter += _printf(string);
			percentage_mode = 0;
		}
		else if (format[i] == ' ' && *percentage_pointer == 1)
		{
			flags[0] = 1;
		}
		else if (format[i] == '+' && *percentage_pointer == 1)
		{
			flags[1] = 1;
		}
		else if (format[i] == '-' && *percentage_pointer == 1)
		{
			flags[2] = 1;
		}
		else if (format[i] == '#' && *percentage_pointer == 1)
		{
			flags[3] = 1;
		}
		else if (format[i] == '0' && *percentage_pointer == 1 && numbers_mode == 0)
		{
			flags[4] = 1;
		}
		else if (format[i] == 'l' && *percentage_pointer == 1)
		{
			flags[6] = 1;
		}
		else if (format[i] == 'h' && *percentage_pointer == 1)
		{
			flags[6] = 2;
		}
		else if (format[i] >= '0' && format[i] <= '9' && *percentage_pointer == 1)
		{
			numbers_mode = 1;
			number_result = (number_result * 10) + format[i] + 48;
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
