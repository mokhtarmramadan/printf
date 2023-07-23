#include <stdarg.h>
#include <string.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - a function that produces output according to a format
 * @format: string.
 *Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i;
	int number;
	int c;
	char *s;
	int d;

	va_start(ap, format);
	i = 0;
	number = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(ap, int);

				number += write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				s = va_arg(ap, char *);
				d = 0;
				while (s[d] != '\0')
				{

					number += write(1, &s[d], 1);
					d++;
				}
			}
			else if (format[i] == '%')
			{
				number += write(1, "%", 1);
			}
			else
			{
				number += write(1, "%", 1);
				number += write(1, &format[i], 1);
			}
		}
		else
		{
			number += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(ap);

	return (number);
}
