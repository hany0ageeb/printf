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
	unsigned long int value;
	char *temp, *formatted_value;
	int i, j;

	if (pspec != NULL && pspec->specifier == 'p')
	{
		value = (unsigned long int)va_arg(argptr, void *);
		if (value == 0)
		{
			formatted_value = malloc(sizeof(char) * 2);
			formatted_value[0] = '0';
			formatted_value[1] = '\0';
		}
		else
		{
			temp = int_to_str((long int)value, hexadecimal);
			formatted_value = malloc(sizeof(char) * (_strlen(temp) + 3));
			formatted_value[0] = '0';
			formatted_value[1] = 'x';
			for (i = 2, j = 0; temp[j] != '\0'; ++j, ++i)
				formatted_value[i] = temp[j];
			formatted_value[i] = '\0';
			free(temp);
		}
	}
	return (formatted_value);
}

