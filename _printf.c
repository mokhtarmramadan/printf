#include <stdarg.h>
#include <stdlib.h>
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
	int integer;
	int div;
	char digit;

	va_start(ap, format);
	i = 0;
	number = 0;
	integer = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch(format[i])
			{
				case 'c':
					c = va_arg(ap, int);
					number += write(1, &c, 1);
					break;

				case 's':
			
					s = va_arg(ap, char *);
					if (s == NULL)
					{
						s = "(null)";
					}
					d = 0;
					while (s[d] != '\0')
					{

						number += write(1, &s[d], 1);
						d++;
					}
					break;

				case '%':
					number += write(1, "%", 1);
					break;

				case 'i':
				case 'd':
					integer = va_arg(ap, int);
                    			if (integer < 0)
                    			{
                        			write(1, "-", 1);
                        			number++;
                        			integer = -integer;
                    			}

                    			div = 1;
                    			while (integer / div >= 10)
					{
                        			div *= 10;
					}
                    			while (div > 0)
                    			{
                        			digit = integer / div + '0';
                        			write(1, &digit, 1);
                        			number++;
                        			integer %= div;
                        			div/= 10;
                    			}
                    			break;

				default:
					number += write(1, "Error: invalid format specifier\n", 35);;
					exit(1);
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
