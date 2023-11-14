#include "main.h"
/**
* print_S - function prints the formatted representation
* of a string with special characters.
*
* This function takes a string as input, and for each character that falls
* outside the printable ASCII range, it prints its hex representation.
*
* @arguments: The variable arguments list containing the string.
* @buffer: The buffer to store the formatted output.
* @buffer_index: The current index in the buffer.
*
* Return: The total number of characters printed to the buffer.
*/

int print_S(va_list arguments, char *buffer, unsigned int buffer_index)
{
	unsigned char *str = va_arg(arguments, unsigned char *);

	char *bin = malloc(sizeof(char) * (32 + 1));

	char *hex = malloc(sizeof(char) * (8 + 1));

	unsigned int sum, i, index;

	for (sum = i = 0; str[i]; i++)

	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer_index = handle_buffer(buffer, '\\', buffer_index);
			buffer_index = handle_buffer(buffer, 'x', buffer_index);

			index = str[i];

			bin = convert_bin(bin, index, 0, 32);
			hex = convert_hex(bin, hex, 1, 8);

			buffer_index = handle_buffer(buffer, hex[6], buffer_index);
			buffer_index = handle_buffer(buffer, hex[7], buffer_index);

			sum = sum + 3;
		}
		else
		{
			buffer_index = handle_buffer(buffer, str[i], buffer_index);
		}
	}

	free(bin);
	free(hex);

	return (i + sum);
}
