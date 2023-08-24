#include "main.h"
#include <stdarg.h>
/**
 * handle_b_spec - handle custom specifier b
 * @spec: conversion specification
 * @argptr: var args
 * Return: formatted value
 */
char *handle_b_spec(const conv_spec_t *spec, va_list argptr)
{
	char *formatted_value = NULL;
	long int value;

	if (spec != NULL && spec->specifier == 'b')
	{
		value = va_arg(argptr, unsigned int);
		formatted_value = int_to_str(value, binary);
	}
	return (formatted_value);
}

