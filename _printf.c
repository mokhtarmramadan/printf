#include <stdarg.h>
#include <string.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - prints output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, number;

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
				number += write(1, &va_arg(ap, int), 1);
			}
			else if (format[i] == 's')
			{
				number += write(1, va_arg(ap, char *), strlen(va_arg(ap, char *)));
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
