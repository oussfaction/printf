#include "main.h"

void write_buffer(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed_count = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
			{
				write_buffer(buffer, &buff_index);
			}
			printed_chars++;
		}
		else
		{
			write_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed_count = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed_count == -1)
				return (-1);
			printed_chars += printed_count;
		}
	}

	write_buffer(buffer, &buff_index);

	va_end(args);

	return (printed_chars);
}

/**
 * write_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void write_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
	{
		write(1, &buffer[0], *buff_index);
	}

	*buff_index = 0;
}
