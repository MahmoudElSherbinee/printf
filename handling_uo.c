#include "main.h"

/**
* print_u - function prints an unsigned integer to the buffer.
*
* This function takes an unsigned integer as an argument and prints its
* digits to the provided buffer.
*
* @arguments: The variable arguments list containing the unsigned integer.
* @buffer: The buffer to store the formatted output.
* @buffer_index: The current index in the buffer.
*
* Return: The number of digits printed.
*/

int print_u(va_list arguments, char *buffer, unsigned int buffer_index)
{
	unsigned int value = va_arg(arguments, unsigned int);

	int x = 0;

	unsigned int divisor = 1;

	unsigned int temp = value;

	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		char digit = ((value / divisor) % 10) + '0';

		buffer_index = handle_buffer(buffer, digit, buffer_index);
		x++;
		divisor /= 10;
	}

	return (x);
}

/**
* print_o - function prints the octal representation
*of an integer to the buffer.
*
* This function converts the given integer to its octal representation and
* adds the octal digits to the provided buffer.
*
* @arguments: The variable arguments list containing the integer.
* @buffer: The buffer to store the formatted output.
* @buffer_index: The current index in the buffer.
*
* Return: The number of octal digits printed.
*/
int print_o(va_list arguments, char *buffer, unsigned int buffer_index)
{
	int first_digit = 0;
	int x = 0;
	int is_negative;
	int i;

	char *bin;
	char *oct;

	int value = va_arg(arguments, int);

	if (value == 0)
	{
		buffer_index = handle_buffer(buffer, '0', buffer_index);
		return (1);
	}
	is_negative = (value < 0) ? (value = (value * -1) - 1, 1) : 0;

	bin = malloc(sizeof(char) * (32 + 1));
	bin = convert_bin(bin, value, is_negative, 32);

	oct = malloc(sizeof(char) * (11 + 1));
	oct = convert_bin_oct(bin, oct);
	for (i = 0; oct[i]; i++)

	{
		if (oct[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			buffer_index = handle_buffer(buffer, oct[i], buffer_index);
			x++;
		}
	}
	free(bin);
	free(oct);
	return (x);
}
