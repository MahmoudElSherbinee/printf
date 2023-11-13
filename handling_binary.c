#include "main.h"

/**
* convert_to_binary - function converts an unsigned integer to binary.
*
* @value: The unsigned integer to convert.
* @binary_buffer: The buffer to store the binary representation.
*
* Return: The length of the binary representation.
*/
int convert_to_binary(unsigned int value, char *binary_buffer)
{
	int index = 0;

	int i, j;

	if (value == 0)
	{
		binary_buffer[0] = '0';
		binary_buffer[1] = '\0';
		return (1);
	}

	while (value > 0)
	{
		binary_buffer[index++] = (value % 2) + '0';
		value /= 2;
	}

	for (i = 0, j = index - 1; i < j; i++, j--)
	{
		char temp = binary_buffer[i];

		binary_buffer[i] = binary_buffer[j];
		binary_buffer[j] = temp;
	}

	binary_buffer[index] = '\0';
	return (index);
}

/**
* handle_binary - function handles the formatting
*of an unsigned int in binary for printing.
*
* @arguments: The variable arguments list
*    containing the unsigned int to format.
* @buffer: The buffer to store the formatted output.
* @buffer_index: The current index in the buffer.
*
* Return: The length of the formatted binary string.
*/
int handle_binary(va_list arguments, char *buffer, unsigned int buffer_index)
{
	int i;

	unsigned int value = va_arg(arguments, unsigned int);

	char binary_buffer[33];

	int binary_length = convert_to_binary(value, binary_buffer);

	for (i = 0; i < binary_length; i++)

	{
		buffer_index = handle_buffer(buffer, binary_buffer[i], buffer_index);
	}

	return (binary_length);
}
