#include "main.h"
#include <stdarg.h>
/**
 * handle_length_modifier_for_unsigned - read unsigned value from argptr
 * @spec: spec
 * @argptr: var args
 * Return: next value int argptr
 */
long int handle_length_for_unsigned(
		const conversion_specification_t *spec,
		va_list argptr)
{
	unsigned long int value;

	if (spec->length_modifier == NULL)
		value = va_arg(argptr, unsigned int);
	else if (spec->length_modifier[0] == 'l')
		value = va_arg(argptr, unsigned long int);
	else if (spec->length_modifier[0] == 'h')
		value = (unsigned short int)va_arg(argptr, unsigned int);
	else
		value = va_arg(argptr, unsigned int);
	return ((long int)value);
}
/**
 * handle_len_mod_for_signed - read signed int from argptr
 * @spec: spec
 * @argptr: argptr
 * Return: long int
 */
long int handle_len_mod_for_signed(const conversion_specification_t *spec,
		va_list argptr)
{
	long int value;

	if (spec->length_modifier == NULL)
		value = va_arg(argptr, int);
	else if (spec->length_modifier[0] == 'h')
		value = (short int)va_arg(argptr, int);
	else if (spec->length_modifier[0] == 'l')
		value = va_arg(argptr, long int);
	else
		value = va_arg(argptr, int);
	return (value);
}

