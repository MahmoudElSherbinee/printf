#include "main.h"

/**
* print_address - function prints the
* formatted representation of a memory address.
*
* This function takes a memory address as input and prints its hex
* representation, or "(nil)" if the address is NULL.
*
* @arguments: The variable arguments list containing the memory address.
* @buffer: The buffer to store the formatted output.
* @buffer_index: The current index in the buffer.
*
* Return: The total number of characters printed to the buffer.
*/

int print_address(va_list arguments, char *buffer, unsigned int buffer_index)
{
	void *addres = va_arg(arguments, void *);
	int i, x, is_negative, index;
	long int input;
	char *bin = malloc(sizeof(char) * (64 + 1));
	char *hex = malloc(sizeof(char) * (16 + 1));
	char default_s[] = "(nil)";

	if (addres == NULL)
	{
		for (i = 0; default_s[i]; i++)
		{
			buffer_index = handle_buffer(buffer, default_s[i], buffer_index);
		}
		return (5);
	}
	input = (intptr_t)addres;
	is_negative = 0;
	if (input < 0)
	{input = (input * -1) - 1;
		is_negative = 1;
	}
	bin = convert_bin(bin, input, is_negative, 64);
	hex = convert_hex(bin, hex, 0, 16);
	buffer_index = handle_buffer(buffer, '0', buffer_index);
	buffer_index = handle_buffer(buffer, 'x', buffer_index);
	index = 0;
	x = 0;
	for (i = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && index == 0)
		{index = 1;
		}
		if (index)
		{buffer_index = handle_buffer(buffer, hex[i], buffer_index);
			x++;
		}
	}
	free(bin);
	free(hex);
	return (x + 2);
}
