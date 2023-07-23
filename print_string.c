#include "main.h"
#include <unistd.h>


int print_string(char *s, int number)
{
	int d;

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
	return (number);
}
