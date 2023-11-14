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
	unsigned int x, y, z;
	char default_alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot_alpha[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	char *input_string = va_arg(arguments, char *);

	if (input_string == NULL)
	{
		const char *default_s = "(avyy)";

		for (x = 0; default_s[x]; x++)
			buffer_index = handle_buffer(buffer, default_s[x], buffer_index);
		return (6);
	}


	for (x = 0; input_string[x] != '\0'; x++)
	{
		for (z = y = 0; default_alpha[y]; y++)
		{
			if (input_string[x] == default_alpha[y])
			{
				z = 1;
				buffer_index = handle_buffer(buffer, rot_alpha[y], buffer_index);
				break;
			}
		}
		if (z == 0)
			buffer_index = handle_buffer(buffer, input_string[x], buffer_index);
	}

	return (x);
}
