#include "main.h"
#include <stdarg.h>
/**
 * handle_c_spec - handle c conversion specifier
 * @pspec: conversion specifiction
 * @argptr: var args
 * Return: formatted value
 */
char *handle_c_spec(const conv_spec_t *pspec, va_list argptr)
{
	char *formatted_value = NULL;
	char c;

	if (pspec != NULL && pspec->specifier == 'c')
	{
		c = va_arg(argptr, int);
		formatted_value = _str(c, 1);
	}
	return (formatted_value);
}
/**
 * handle_s_spec - handle s conversion specifier
 * @pspec: conversion specification
 * @argptr: var args
 * Return: formatted value
 */
char *handle_s_spec(const conv_spec_t *pspec, va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;

	if (pspec != NULL && pspec->specifier == 's')
	{
		temp = va_arg(argptr, char *);
		formatted_value = copy_str(temp);
	}
	return (formatted_value);
}
/**
 * handle_per_spec - handle % conversion specifier
 * @pspec: conversion specification
 * @argptr: var args
 * Return: formatted value
 */
char *handle_per_spec(
		__attribute__((unused)) const conv_spec_t *pspec,
		__attribute__((unused)) va_list argptr)
{
	char *formatted_value = _str('%', 1);

	return (formatted_value);
}
/**
 * handle_d_spec - handle d, i conversion specifiers
 * @pspec: conversion specification
 * @argptr: var args
 * Return: formatted value
 */
char *handle_d_spec(const conv_spec_t *pspec, va_list argptr)
{
	int value;
	char *formatted_value = NULL;

	if (pspec != NULL && (pspec->specifier == 'd' || pspec->specifier == 'i'))
	{
		value = va_arg(argptr, int);
		formatted_value = int_to_str(value, decimal);
	}
	return (formatted_value);
}

