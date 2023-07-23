#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);

int main()
{
	_printf("th");
	return (0);
}

int _printf(const char *format, ...)
{
        int i;
	char c;
	va_list
        i = 1;
        while (format[i] != '\n')
        {
		printf("%c", format[i]);
                i++;
        }
        return (i + 1);
}
