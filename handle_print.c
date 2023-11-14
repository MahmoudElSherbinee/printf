#include "main.h"

/**
 * print_unt - Custom printf specifier for unsigned integers
 * @arguments: Variable arguments list
 * @buf: Buffer to store the formatted string
 * @ibuf: Current index in the buffer
 *
 * Return: Number of characters written to the buffer
 */
int print_unt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned int int_in, int_temp, i, div;

	int_in = va_arg(arguments, unsigned int);
	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}

	return (i);
}

/**
 * print_u - Custom printf specifier for unsigned integers (u)
 * @arguments: Variable arguments list
 * @buf: Buffer to store the formatted string
 * @ibuf: Current index in the buffer
 *
 * Return: Number of characters written to the buffer
 */
int print_u(va_list arguments, char *buf, unsigned int ibuf)
{
	return (print_unt(arguments, buf, ibuf));
}

/**
 * print_o - Custom printf specifier for octal integers (o)
 * @arguments: Variable arguments list
 * @buf: Buffer to store the formatted string
 * @ibuf: Current index in the buffer
 *
 * Return: Number of characters written to the buffer
 */
int print_o(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned int octal, temp;
	int i, j;
	char *output;

	octal = va_arg(arguments, unsigned int);
	temp = octal;

	for (i = 0; temp > 0; i++)
		temp /= 8;

	output = malloc(i);

	if (!output)
		return (-1);

	for (i -= 1; i >= 0; i--)
	{
		output[i] = (octal % 8) + '0';
		octal /= 8;
	}

	for (j = 0; output[j]; j++)
		ibuf = handl_buf(buf, output[j], ibuf);

	free(output);

	return (j);
}

/**
 * print_x - Custom printf specifier for hexadecimal integers (x)
 * @arguments: Variable arguments list
 * @buf: Buffer to store the formatted string
 * @ibuf: Current index in the buffer
 *
 * Return: Number of characters written to the buffer
 */
int print_x(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned int hex;
	int i, j;
	char *output;

	hex = va_arg(arguments, unsigned int);

	if (hex == 0)
		return (handl_buf(buf, '0', ibuf));

	for (i = 0; hex > 0; i++)
	{
		if ((hex % 16) < 10)
			output[i] = (hex % 16) + '0';
		else
			output[i] = (hex % 16) + 'a' - 10;
		hex /= 16;
	}

	output = malloc(i);

	if (!output)
		return (-1);

	for (i -= 1; i >= 0; i--)
		ibuf = handl_buf(buf, output[i], ibuf);

	free(output);

	return (j);
}

/**
 * print_X - Custom printf specifier for uppercase hexadecimal integers (X)
 * @arguments: Variable arguments list
 * @buf: Buffer to store the formatted string
 * @ibuf: Current index in the buffer
 *
 * Return: Number of characters written to the buffer
 */
int print_X(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned int hex;
	int i, j;
	char *output;

	hex = va_arg(arguments, unsigned int);

	if (hex == 0)
		return (handl_buf(buf, '0', ibuf));

	for (i = 0; hex > 0; i++)
	{
		if ((hex % 16) < 10)
			output[i] = (hex % 16) + '0';
		else
			output[i] = (hex % 16) + 'A' - 10;
		hex /= 16;
	}

	output = malloc(i);

	if (!output)
		return (-1);

	for (i -= 1; i >= 0; i--)
		ibuf = handl_buf(buf, output[i], ibuf);

	free(output);

	return (j);
}
