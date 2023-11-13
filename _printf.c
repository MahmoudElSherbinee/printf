#include "main.h"

/**
 * _printf - Implements a simplified printf function with variable arguments.
 *
 * This function processes a format string, iterates through it, and handles
 * formatting logic for '%' specifiers by calling appropriate print functions.
 * It updates the length and buffer index accordingly, and the final output is
 * written to the standard output.
 *
 * @format: The format string containing format specifiers.
 * @...: Variable arguments corresponding to the format specifiers.
 *
 * Return: The total number of characters written, or -1 on error.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, length = 0, buffer_index = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format[i])
		return (0);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	out_buffer(buffer, buffer_index), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = print_function(format, i + 1);
				if (function != NULL)
				{
					length += function(arguments, buffer, buffer_index);
					i += calc_length(format, i + 1);
				}
				else
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buffer(buffer, format[i], buffer_index), length++, i--;
				}
			} i++;
		}
		else
			handle_buffer(buffer, format[i], buffer_index), length++;
		for (buffer_index = length; buffer_index > 1024; buffer_index -= 1024)
			;
	}
	out_buffer(buffer, buffer_index), free(buffer), va_end(arguments);
	return (length);
}
