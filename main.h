#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
/*structs*/

/**
 * struct type - Short description
 * @specifier: First member
 * @func: Second member
 *
 * Description: define a new type struct type with the following elements
 */
typedef struct type
{
	char *specifier;

	int (*function)(va_list, char *, unsigned int);

} type;

/*main functions*/
int _printf(const char *format, ...);
int (*print_function(const char *s, int index))(va_list, char *, unsigned int);
int out_buffer(char *buffer, unsigned int nbuf);
unsigned int handle_buffer(char *buffer, char c, unsigned int buffer_index);
int handle_char(va_list arguments, char *buffer, unsigned int buffer_index);
int calc_length(const char *s, int index);
int handle_string(va_list arguments, char *buffer, unsigned int buffer_index);
int handle_int(va_list arguments, char *buf, unsigned int buffer_index);
int handle_percent(va_list arguments, char *buffer, unsigned int buffer_index);
int convert_to_binary(unsigned int value, char *binary_buffer);
int handle_binary(va_list arguments, char *buffer, unsigned int buffer_index);
int handle_symbols(va_list arguments, char *buffer, unsigned int buffer_index);





#endif /* MAIN_H */
