#include "main.h"
/**
* print_function - Returns a function pointer based on
*	the format specifier at the given index.
*
* This function searches for a format specifier in the provided format string
* starting from the given index. It matches the specifier against a predefined
*	array of specifiers.
* and returns a function pointer to the corresponding printing
*	function for that specifier.
*
* @s: The format string.
* @index: The starting index to search for a format specifier.
* Return: A function pointer to the printing function
* for the matched specifier,or NULL if no match is found.
*/

int (*print_function(const char *s, int index))(va_list, char *, unsigned int)
{
	type sp_func_check[] = {
		{"c", handle_char}, {"s", handle_string}, {"b", handle_binary},
		{"d", handle_int}, {"i", handle_int}, {"#i", handle_int}, {"#d", handle_int},
		{"%", handle_percent}, {" %", handle_percent},
		{"l", handle_percent}, {"h", handle_percent},
		{"+i", handle_symbols}, {" +i", handle_symbols}, {"+ i", handle_symbols},
		{"+d", handle_symbols}, {" +d", handle_symbols}, {"+ d", handle_symbols},
		{"r", print_reversed}, {"R", handle_ROT},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (sp_func_check[i].specifier)
	{
		if (s[index] == sp_func_check[i].specifier[j])
		{
			if (sp_func_check[i].specifier[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (sp_func_check[i].function);
}

/**
* calc_length - function calculates the length
* of a format specifier at the given index.
*
* This function searches for a format specifier in the provided format string
* starting from the given index. It matches the specifier against a predefined
* array of specifiers and returns the length of the matched specifier.
*
* @s: The format string.
* @index: The starting index to search for a format specifier.
*
* Return: The length of the matched format specifier,
* or 0 if no match is found.
*/

int calc_length(const char *s, int index)
{
	type sp_func_check[] = {
		{"c", handle_char}, {"s", handle_string}, {"b", handle_binary},
		{"d", handle_int}, {"i", handle_int}, {"#i", handle_int}, {"#d", handle_int},
		{"%", handle_percent}, {" %", handle_percent},
		{"l", handle_percent}, {"h", handle_percent},
		{"+i", handle_symbols}, {" +i", handle_symbols}, {"+ i", handle_symbols},
		{"+d", handle_symbols}, {" +d", handle_symbols}, {"+ d", handle_symbols},
		{"r", print_reversed}, {"R", handle_ROT},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (sp_func_check[i].specifier)
	{
		if (s[index] == sp_func_check[i].specifier[j])
		{
			if (sp_func_check[i].specifier[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (j);
}
