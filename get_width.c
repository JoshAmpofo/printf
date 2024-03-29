#include "main.h"

/**
 * get_width - computes args width for printing
 * @format: formatted string in which to print the arguments
 * @i: arguments received by printf to be printed
 * @list: variadic list of arguments
 *
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i, width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
