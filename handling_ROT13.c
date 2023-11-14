#include "main.h"

/**
 * handle_ROT - function handle the %R conversion specifier (ROT13).
 *
 * @arguments: Variable arguments list.
 * @buffer: Pointer to the output buffer.
 * @buffer_index: Index for the buffer pointer.
 * Return: The number of characters printed.
 */
int handle_ROT(va_list arguments, char *buffer, unsigned int buffer_index)
{
	unsigned int i;

	char *input_string = va_arg(arguments, char *);

	if (input_string == NULL)
	{
		return (buffer_index);
	}

	for (i = 0; input_string[i] != '\0'; i++)

	{
		char current_char = input_string[i];

		if ('A' <= current_char && current_char <= 'Z')
		{
			current_char = ((current_char - 'A' + 13) % 26) + 'A';
		}
		else if ('a' <= current_char && current_char <= 'z')
		{
			current_char = ((current_char - 'a' + 13) % 26) + 'a';
		}

		buffer_index = handle_buffer(buffer, current_char, buffer_index);
	}

	return (buffer_index);
}
