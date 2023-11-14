#include "main.h"
/**
* convert_bin - function fills a character array
*with the binary representation of a long integer.
*
* This function fills a character array
*with the binary representation of a given long integer.
*
* @bin: The character array to store the binary representation.
* @int_input: The long integer to convert to binary.
* @is_negative: Flag indicating if the integer is negative.
* @limit: The limit of binary digits to consider.
*
* Return: The binary representation stored in the character array.
*/
char *convert_bin(char *bin, long int int_input,
						int is_negative, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
	{
		bin[i] = '0';
	}
	bin[limit] = '\0';

	for (i = limit - 1; int_input > 1; i--)
	{
		if (int_input == 2)
		{
			bin[i] = '0';
		}
		else
		{
			bin[i] = (int_input % 2) + '0';
		}
		int_input /= 2;
	}

	if (int_input != 0)
	{
		bin[i] = '1';
	}

	if (is_negative)
	{
		for (i = 0; bin[i]; i++)
		{
			bin[i] = (bin[i] == '0') ? '1' : '0';
		}
	}

	return (bin);
}

/**
* convert_hex - function fills a character array
* with the hexadecimal representation of a binary string.
*
* This function fills a character array
* with the hexadecimal representation of a binary string.
*
* @bin: The binary string to convert to hexadecimal.
* @hex: The character array to store the hexadecimal representation.
* @is_uppercase: Flag indicating if the hexadecimal letters should be uppercase
* @limit: The limit of hexadecimal digits to consider.
*
* Return: The hexadecimal representation stored in the character array.
*/

char *convert_hex(char *bin, char *hex, int is_uppercase, int limit)
{

	int operation, i, j, to_letter;

	hex[limit] = '\0';

	to_letter = (is_uppercase) ? 55 : 87;

	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (operation = 0, j = 1; j <= 8; j *= 2, i--)
		{
			operation = ((bin[i] - '0') * j) + operation;
		}
		i++;

		if (operation < 10)
		{
			hex[i / 4] = operation + 48;
		}
		else
		{
			hex[i / 4] = operation + to_letter;
		}
	}

	return (hex);
}

/**
* convert_bin_oct - function converts a binary string to octal representation.
*
* This function converts the provided binary string to its octal representation
* and stores it in the destination character array.
*
* @binary: The binary string to convert.
* @octal: The character array to store the octal representation.
*
* Return: The octal representation stored in the character array.
*/
char *convert_bin_oct(char *binary, char *octal)
{
	int operation, i, j, octal_index, limit;

	octal[11] = '\0';

	for (i = 31, octal_index = 10; i >= 0; i--, octal_index--)
	{
		limit = (i > 1) ? 4 : 2;

		for (operation = 0, j = 1; j <= limit; j *= 2, i--)
		{
			operation = ((binary[i] - '0') * j) + operation;
		}
		i++;

		octal[octal_index] = operation + '0';
	}

	return (octal);
}
