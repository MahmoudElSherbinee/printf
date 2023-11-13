#include "main.h"

/**
 * handle_char - function handles the formatting of a character for printing.
 *
 * This function formats a character for printing and stores it in the buffer.
 * The buffer index is then updated accordingly.
 *
 * @arguments: The variable arguments list containing the character to format.
 * @buffer: The buffer to store the formatted output.
 * @buffer_index: The current index in the buffer.
 *
 * Return: The length of the formatted character string (always 1).
 */

int handle_char(va_list arguments, char *buffer, unsigned int buffer_index)
{
	char c;

	c = va_arg(arguments, int);
	handle_buffer(buffer, c, buffer_index);

	return (1);
}
