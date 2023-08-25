#include "main.h"
#include <stdlib.h>
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
		else if (pspec->specifier == 'b')
			pspec->formatter = &handle_b_spec;
		else if (pspec->specifier == 'u')
			pspec->formatter = &handle_u_spec;
		else if (pspec->specifier == 'o')
			pspec->formatter = &handle_u_spec;
		else if (pspec->specifier == 'x')
			pspec->formatter = &handle_u_spec;
		else if (pspec->specifier == 'X')
			pspec->formatter = &handle_u_spec;
		else if (pspec->specifier == 'S')
			pspec->formatter = &handle_S_spec;
		else if (pspec->specifier == 'p')
			pspec->formatter = &handle_p_spec;
		else if (pspec->specifier == 'r')
			pspec->formatter = &hanlde_r_spec;
		else if (pspec->specifier == 'R')
			pspec->formatter = &handle_R_spec;
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

