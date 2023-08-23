#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _format - format
 * @format: format string
 * @format_len: format string length
 * @start: start index
 * @argptr: arg pointer
 * Return: formatted value
 */
char *_format(const char *format, unsigned int *start,
		const unsigned int format_len, va_list argptr)
{
	char *formatted_value = NULL;
	int end;
	conversion_specification_t *specification;

	end = index_of(format, (*start) + 1, format_len, CONVERSION_SPECIFIERS);
	if (end != -1)
	{
		specification = interpret_specification(format, *start, end);
		if (specification->handler != NULL)
		{
			formatted_value = specification->handler(specification, argptr);
		}
		*start = end;
		free_specification(specification);
	}
	else
	{
		*start = format_len - 1;
	}
	return (formatted_value);
}
/**
 * _printf - a cheap clone for printf!
 * @format: format string
 * Return: number of char written
 */
int _printf(const char *format, ...)
{
	int count = 0;
	unsigned int i, buff_index, format_len;
	va_list argptr1;
	char *data, *buffer = NULL;

	if (format != NULL)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		i = 0;
		buff_index = 0;
		format_len = _strlen(format);
		va_start(argptr1, format);
		while (i < format_len)
		{
			if (format[i] == '%')
			{
				data = _format(format, &i, format_len, argptr1);
				if (data != NULL)
				{
					count += _write_str(buffer, &buff_index, BUFFER_SIZE, data);
					free(data);
				}
			}
			else
			{
				count += _write_char(buffer, &buff_index, BUFFER_SIZE, format[i]);
			}
			i++;
		}
	}
	count += _flush(buffer, _strlen(buffer));
	va_end(argptr1);
	free(buffer);
	return (count);
}
