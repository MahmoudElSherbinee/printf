#include "main.h"

/**
 * handle_string - function handles the formatting of a string for printing.
 *
 * This function formats a string for printing and stores it in the buffer.
 * If the input string is NULL, it prints "(null)". The buffer index is
 * then updated accordingly.
 *
 * @arguments: The variable arguments list containing the string to format.
 * @buffer: The buffer to store the formatted output.
 * @buffer_index: The current index in the buffer.
 *
 * Return: The length of the formatted string,
 * or 6 if the input string is NULL.
 */

int handle_string(va_list arguments, char *buffer, unsigned int buffer_index)
{
	char *str;

	unsigned int i;

	char nul[] = "(null)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nul[i]; i++)
			buffer_index = handle_buffer(buffer, nul[i], buffer_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
		buffer_index = handle_buffer(buffer, str[i], buffer_index);
	return (i);
}


/**
 * handle_percent - function handles the formatting
 * of the '%' character for printing.
 *
 * This function is called when the '%' character is encountered
 * in the format string.
 * It adds the '%' character to the buffer.
 *
 * @arguments: The variable arguments list (unused).
 * @buffer: The buffer to store the formatted output.
 * @buffer_index: The current index in the buffer.
 *
 * Return: Always returns 1 (length of '%').
 */

int handle_percent(va_list arguments, char *buffer, unsigned int buffer_index)
{

	(void)arguments;

	buffer_index = handle_buffer(buffer, '%', buffer_index);

	return (1);
}
