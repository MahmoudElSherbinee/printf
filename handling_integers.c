#include "main.h"

/**
* handle_int - function handles the formatting of an integer for printing.
* This function formats an integer for printing by converting it to a string
* representation. It considers the sign of the integer and adds a minus sign
* if necessary. The formatted string is stored in the buffer, and the buffer
* index is updated accordingly.
*
* @arguments: The variable arguments list containing the integer to format.
* @buffer: The buffer to store the formatted output.
* @buffer_index: The current index in the buffer.
*
* Return: The length of the formatted integer string, including the sign.
*/

int handle_int(va_list arguments, char *buffer, unsigned int buffer_index)
{
	int input;

	unsigned int in, temp, i, div, is_negative;

	input = va_arg(arguments, int);
	is_negative = 0;
	if (input < 0)
	{
		in = input * -1;
		buffer_index = handle_buffer(buffer, '-', buffer_index);
		is_negative = 1;
	}
	else
	{
		in = input;
	}

	temp = in;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_index = handle_buffer(buffer, ((in / div) % 10) + '0', buffer_index);
	}
	return (i + is_negative);
}

/**
* handle_symbols - function print an integer with a proper sign symbol.
*
* @arguments: Input arguments.
* @buffer: Pointer to the output buffer.
* @buffer_index: Index for the buffer pointer.
*
* Return: Number of characters printed.
*/
int handle_symbols(va_list arguments, char *buffer, unsigned int buffer_index)
{
	int input;

	unsigned int abs_val, temp, i, div;

	input = va_arg(arguments, int);

	if (input < 0)
	{
		abs_val = (unsigned int)(-input);

		buffer_index = handle_buffer(buffer, '-', buffer_index);
	}
	else
	{
		abs_val = (unsigned int)input;

		buffer_index = handle_buffer(buffer, '+', buffer_index);
	}

	temp = abs_val;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_index = handle_buffer(buffer,
		((abs_val / div) % 10) + '0', buffer_index);
	}

	return (i + 1);
}
