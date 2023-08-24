#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
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
/**
 * calc_len_for_S_spec - calc length required to format temp accorrding to S
 * @temp: string
 * Return: required length
 */
int calc_len_for_S_spec(const char *temp)
{
	int len = 0, i = 0;

	for (; temp[i] != '\0'; ++i)
	{
		if ((temp[i] > 0 && temp[i] < 32) || temp[i] >= 127)
			len += 4;
		else
			len++;
	}
	return (len);
}
/**
 * handle_S_specifier - handle S custom specifier
 * @spec: spec
 * @argptr: args
 * Return: formatted value
 */
char *handle_S_spec(const conv_spec_t *spec, va_list argptr)
{
	int len = 0, i = 0, j = 0;
	char *temp = NULL, *formatted_value = NULL, *hex_code;

	if (spec != NULL && spec->specifier == 'S')
	{
		temp = va_arg(argptr, char *);
		if (temp == NULL)
			return (formatted_value);
		len = calc_len_for_S_spec(temp);
		formatted_value = malloc(sizeof(char) * (len + 1));
		if (formatted_value == NULL)
			return (formatted_value);
		for (i = 0; temp[i] != '\0'; ++i)
		{
			if ((temp[i] > 0 && temp[i] < 32) || temp[i] >= 127)
			{
				formatted_value[j] = '\\';
				formatted_value[j + 1] = 'x';
				hex_code = int_to_str(temp[i], hexadecimal);
				if (temp[i] < (int)hexadecimal)
				{
					formatted_value[j + 2] = '0';
					formatted_value[j + 3] = hex_code[0];
				}
				else
				{
					formatted_value[j + 2] = hex_code[0];
					formatted_value[j + 3] = hex_code[1];
				}
				free(hex_code);
				j += 2;
			}
			else
				formatted_value[j] = temp[i];
			j++;
		}
		formatted_value[len] = '\0';
	}
	return (formatted_value);
}
