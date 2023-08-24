#include "main.h"
/**
 * set_conv_spec_formatter - set the formatter pointer to correct func or null
 * @pspec: conversion specification
 * Return: void
 */
void set_conv_spec_formatter(conv_spec_t *pspec)
{
	if (pspec != NULL)
	{
		if (pspec->specifier == 'c')
			pspec->formatter = &handle_c_spec;
		else if (pspec->specifier == 's')
			pspec->formatter = &handle_s_spec;
		else if (pspec->specifier == '%')
			pspec->formatter = &handle_per_spec;
		else if (pspec->specifier == 'd' || pspec->specifier == 'i')
			pspec->formatter = &handle_d_spec;
		else
			pspec->formatter = NULL;
	}
}
/**
 * free_conv_spec - free memory used by pspec
 * @pspec: conversion spec
 * Return: void
 */
void free_conv_spec(conv_spec_t *pspec)
{
	if (pspec != NULL)
	{
		free(pspec->flag);
		free(pspec);
	}
}

