#include "main.h"

/**
* print_x - Custom printf specifier for hex integers (x)
* @arguments: Variable arguments list
* @buffer: Buffer to store the formatted string
* @buffer_index: Current index in the buffer
*
* Return: Number of characters written to the buffer
*/

int print_x(va_list arguments, char *buffer, unsigned int buffer_index)
{
	int int_input = va_arg(arguments, int);

	unsigned int i;

	int isnegative = 0;

	int first_digit = 0;

	char *hex, *bin;

	if (int_input < 0)
	{
		int_input = (-int_input) - 1;
		isnegative = 1;
	}

	bin = malloc(sizeof(char) * (32 + 1));
	bin = convert_bin(bin, int_input, isnegative, 32);

	hex = malloc(sizeof(char) * (8 + 1));
	hex = convert_hex(bin, hex, 0, 8);

	for (i = 0; hex[i]; i++)

	{
		if (hex[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			buffer_index = handle_buffer(buffer, hex[i], buffer_index);
		}
	}

	free(bin);
	free(hex);
	return (buffer_index);
}

/**
* print_X - Custom printf specifier for uppercase hex integers (X)
* @arguments: Variable arguments list
* @buffer: Buffer to store the formatted string
* @buffer_index: Current index in the buffer
*
* Return: Number of characters written to the buffer
*/

int print_X(va_list arguments, char *buffer, unsigned int buffer_index)
{
	int input_value, i, is_negative, digit_count, first_digit;

	char *bin_rep, *hex_rep;

	input_value = va_arg(arguments, int);
	is_negative = 0;
	if (input_value == 0)
	{
		buffer_index = handle_buffer(buffer, '0', buffer_index);
		return (1);
	}
	if (input_value < 0)
	{
		input_value = (input_value * -1) - 1;
		is_negative = 1;
	}
	bin_rep = malloc(sizeof(char) * (32 + 1));
	bin_rep = convert_bin(bin_rep, input_value, is_negative, 32);
	hex_rep = malloc(sizeof(char) * (8 + 1));
	hex_rep = convert_hex(bin_rep, hex_rep, 1, 8);

	for (first_digit = i = digit_count = 0; hex_rep[i]; i++)
	{
		if (hex_rep[i] != '0' && first_digit == 0)
		{
			first_digit = 1;
		}

		if (first_digit)
		{
			buffer_index = handle_buffer(buffer, hex_rep[i], buffer_index);
			digit_count++;
		}
	}
	free(bin_rep);
	free(hex_rep);
	return (digit_count);
}
