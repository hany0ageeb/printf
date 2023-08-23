#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * get_width - read width if present from format conv spec
 * @format: format string
 * @pstart: start index
 * @end: end index
 * Return: width if any or 0
 */
int get_width(const char *format, int *pstart, int end)
{
	int i = *pstart, width = 0;

	while (format[i] >= '0' && format[i] <= '9' && format[i] != '\0' && i <= end)
		i++;
	if (i > *pstart)
	{
		width = str_to_int(format, *pstart, i - 1);
		*pstart = i;
	}
	return (width);
}
/**
 * get_percision - read percision if present from format conv sopec
 * @format: format string
 * @pstart: start index
 * @end: end index
 * Return: percison value (0, -1(omitted), or a value)
 */
int get_percision(const char *format, int *pstart, int end)
{
	int percision = -1, i;

	if (format[*pstart] == '.')
	{
		(*pstart)++;
		if (format[*pstart] == '-')
		{
			return (percision);
		}
		else
		{
			i = (*pstart) + 1;
			while (format[i] >= '0' && format[i] <= '9' && format[i] != '\0' && i < end)
				i++;
			if (i - (*pstart) > 1)
			{
				percision = str_to_int(format, *pstart, i - 1);
				*pstart = i;
				return (percision);
			}
			else
			{
				return (0);
			}
		}
	}
	return (percision);
}

/**
 * interpret_specification - convert spec string into parts
 * for further processing
 * @format: format string
 * @start: start index
 * @end: end index
 * Return: specification
 */
conversion_specification_t *interpret_specification(
		const char *format, int start, int end)
{
	conversion_specification_t *specification = NULL;
	int l_flag_idx, l_len_mod_idx;

	if (format != NULL && end >= start)
	{
		specification = malloc(sizeof(conversion_specification_t));
		if (specification != NULL)
		{
			specification->conversion_specifier = format[end];
			l_flag_idx = last_index_of(format, start + 1, end - 1, CONVERSION_FLAGS);
			if (l_flag_idx != -1)
			{
				specification->flag = sub_string(format, start + 1, l_flag_idx);
				l_flag_idx++;
			}
			else
			{
				specification->flag = NULL;
				l_flag_idx = start + 1;
			}
			specification->width = get_width(format, &l_flag_idx, end - 1);
			specification->percision = get_percision(format, &l_flag_idx, end - 1);
			l_len_mod_idx = last_index_of(format, l_flag_idx, end - 1,
					LENGTH_MODIFIERS);
			if (l_len_mod_idx == -1)
			{
				specification->length_modifier = NULL;
			}
			else
			{
				specification->length_modifier = sub_string(format, l_flag_idx,
						l_len_mod_idx);
			}
		}
		set_spec_handler(specification);
	}
	return (specification);
}
/**
 * free_specification - release memory of pspec
 * @pspec: pointer to specification
 * Return: void
 */
void free_specification(conversion_specification_t *pspec)
{
	if (pspec != NULL)
	{
		free(pspec->flag);
		free(pspec->length_modifier);
		free(pspec);
	}
}
/**
 * set_spec_handler - set the handler according to specifier
 * @spec: specifier
 * Return: void
 */
void set_spec_handler(conversion_specification_t *spec)
{
	char c;

	if (spec != NULL)
	{
		c = spec->conversion_specifier;
		if (c == 'c')
			spec->handler = &handle_c_specifier;
		else if (c == 's')
			spec->handler = &handle_s_specifier;
		else if (c == '%')
			spec->handler = &handle_per_specifier;
		else if (c == 'd' || c == 'i')
			spec->handler = &handle_d_i_specifier;
		else if (c == 'u')
			spec->handler = &handle_u_specifier;
		else if (c == 'o')
			spec->handler = &handle_o_specifier;
		else if (c == 'x' || c == 'X')
			spec->handler = &handle_x_specifier;
		else if (c == 'p')
			spec->handler = &handle_p_specifier;
		else if (c == 'b')
			spec->handler = &handle_b_specifier;
		else if (c == 'S')
			spec->handler = &handle_S_specifier;
		else if (c == 'r')
			spec->handler = &handle_r_specifier;
		else if (c == 'R')
			spec->handler = NULL;
		else
			spec->handler = NULL;
	}
}
