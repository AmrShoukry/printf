#include "main.h"
#include <stdargs.h>

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
	int flags[] = {0, 0, 0, 0, 0, 0, 0};
	va_list ap;

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] >= '0' && format[i] <= '9')
		{
			if (format[i] == 0 && numbers_mode == 0)
			{
				if (percentage_mode == 1)
				{

				}
				else
				{
					put_char(format[i]);
					counter++;
				}
			}
			else
			{
				numbers_mode = 1;
				number_result = (number_result * 10) + format[i] + 48;
			}
		}
		if (format[i] == ' ')
		{
			if (percentage_mode == 0)
			{
				put_char(format[i]);
				counter++;
			}
			else
			{
				
			}
		}	
	}

	va_end(ap);

	return (counter);
}
