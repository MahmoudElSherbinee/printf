#include "main.h"

/**
 * print_reversed - function prints a reversed string to a buffer.
 *
 * This function retrieves a string argument from the variable arguments list
 * and prints its characters in reverse order to the specified buffer.
 *
 * @arguments: Variable arguments list.
 * @buffer: Pointer to the output buffer.
 * @buffer_index: Index for the buffer pointer.
 *
 * Return: The length of the original string if not NULL;
 * 6 if the input string is NULL.
 */

int print_reversed(va_list arguments, char *buffer, unsigned int buffer_index)
{
	char *input = va_arg(arguments, char *);

	int length, index;

	if (input == NULL)
	{
		const char default_string[] = "(llun)";

		for (index = 0; default_string[index] != '\0'; index++)
		{
			buffer_index = handle_buffer(buffer, default_string[index], buffer_index);
		}
		return (6);
	}

	for (length = 0; input[length] != '\0'; length++)
	{
	}

	index = length - 1;
	while (index >= 0 && input[index] != '\0')
	{
		buffer_index = handle_buffer(buffer, input[index], buffer_index);
		index--;
	}

	return (length);
}
