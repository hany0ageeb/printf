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
		handle_width(&formatted_value, pspec);
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
		if (temp != NULL)
		{
			formatted_value = copy_str(temp);
		}
		else
		{
			formatted_value = copy_str("(null)");
		}
		handle_width(&formatted_value, pspec);
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
	long int value;
	char *formatted_value = NULL;

	if (pspec != NULL && (pspec->specifier == 'd' || pspec->specifier == 'i'))
	{
		value = handle_len_mod(pspec->len_mod, pspec->specifier, argptr);
		formatted_value = int_to_str(value, decimal);
		handle_flag(&formatted_value, pspec->flag, pspec->specifier);
		handle_width(&formatted_value, pspec);
	}
	return (formatted_value);
}
/**
 * handle_u_spec - handle u o x X specifiers
 * @pspec: conversion specification
 * @argptr: var args
 * Return: formatted value
 */
char *handle_u_spec(const conv_spec_t *pspec, va_list argptr)
{
	long int value;
	char *formatted_value =  NULL;

	if (pspec != NULL &&
			(pspec->specifier == 'u' ||
			 pspec->specifier == 'o' ||
			 pspec->specifier == 'x' ||
			 pspec->specifier == 'X'))
	{
		value = handle_len_mod(pspec->len_mod, pspec->specifier, argptr);
		if (pspec->specifier == 'u')
			formatted_value = int_to_str(value, decimal);
		else if (pspec->specifier == 'o')
			formatted_value = int_to_str(value, octal);
		else if (pspec->specifier == 'x')
			formatted_value = int_to_str(value, hexadecimal);
		else if (pspec->specifier == 'X')
		{
			formatted_value = int_to_str(value, hexadecimal);
			_to_upper(formatted_value);
		}
		handle_flag(&formatted_value, pspec->flag, pspec->specifier);
		handle_width(&formatted_value, pspec);
	}
	return (formatted_value);
}

