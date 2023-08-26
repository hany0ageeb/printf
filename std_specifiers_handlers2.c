#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * handle_p_spec - handle p conv specifier
 * @pspec: spec con
 * @argptr: var args
 * Return: formatted value
 */
char *handle_p_spec(const conv_spec_t *pspec, va_list argptr)
{
	size_t value;
	char *temp, *formatted_value;
	int i, j;

	if (pspec != NULL && pspec->specifier == 'p')
	{
		value = va_arg(argptr, size_t);
		if (value == 0)
		{
			formatted_value = cp_str("(nil)");
		}
		else
		{
			temp = uint_to_str(value, hexadecimal);
			formatted_value = malloc(sizeof(char) * (_strlen(temp) + 3));
			formatted_value[0] = '0';
			formatted_value[1] = 'x';
			for (i = 2, j = 0; temp[j] != '\0'; ++j, ++i)
				formatted_value[i] = temp[j];
			formatted_value[i] = '\0';
			free(temp);
		}
		handle_width(&formatted_value, pspec);
	}
	return (formatted_value);
}
