#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int count = 0;
	char ch = *format;
	va_list args;
	va_start(args, format);

	if (ch == '\0')
		return (count);

	if (ch == '%')
	{
		format++;
		ch = *format;

		if (ch == 'c')
		{
			putchar(va_arg(args, int));
			count++;
		}
		else if (ch == 's')
		{
			char *str = va_arg(args, char *);
			int i;
			for (i = 0; str[i] != '\0'; i++)
			{
				putchar(str[i]);
				count++;
			}
		}
		else if (ch == '%')
		{
			putchar('%');
			count++;
		}
		else
		{
			putchar('%');
			putchar(ch);
			count += 2;
		}
	}
	else
	{
		putchar(ch);
		count++;
	}

	va_end(args);

	return (count);
}
