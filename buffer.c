#include "main.h"

/**
 * out_buffer - function writes the content of the buffer
 * to the standard output.
 *
 * This function writes the content of the given buffer to the standard output.
 *
 * @buffer: The buffer containing the data to be written.
 * @num_buffer: The number of characters in the buffer to be written.
 *
 * Return: The number of characters actually written, or -1 on error.
 */

int out_buffer(char *buffer, unsigned int num_buffer)
{
	return (write(1, buffer, num_buffer));
}

/**
 * handle_buffer - function handles the buffer by adding a character
 * and flushing if necessary.
 *
 * This function adds the specified character to the buffer. If the buffer is
 * full (1024 characters), it flushes the buffer to the standard output and
 * resets the buffer index to 0.
 *
 * @buffer: The buffer to which the character is added.
 * @c: The character to add to the buffer.
 * @buffer_index: The current index in the buffer.
 *
 * Return: The updated buffer index after adding the character.
 */

unsigned int handle_buffer(char *buffer, char c, unsigned int buffer_index)
{
	if (buffer_index == 1024)
	{
		out_buffer(buffer, buffer_index);
		buffer_index = 0;
	}
	buffer[buffer_index] = c;
	buffer_index++;
	return (buffer_index);
}
