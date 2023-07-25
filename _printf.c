#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    int count = 0;	
    va_list args;
    va_start(args, format);
  
    int i;

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            count++;
        }
        else
        {
            i++;
            if (format[i] == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char*);
                int j;
                for (j = 0; str[j] != '\0'; j++)
                {
                    putchar(str[j]);
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                putchar('%');
                count++;
            }
            else if (format[i] == 'r')
            {
                char *str = va_arg(args, char*);
                int j;
                for (j = 0; str[j] != '\0'; j++) {}
                for (j = j - 1; j >= 0; j--)
                {
                    putchar(str[j]);
                    count++;
                }
            }
            else
            {
                putchar('%');
                putchar(format[i]);
                count += 2;
            }
        }
    }

    va_end(args);
    return count;
