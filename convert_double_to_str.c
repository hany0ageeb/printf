#include "main.h"
#include <stdlib.h>
/**
 * convert_double_to_str - convert double to its string rep in base.
 * @num: number
 * @len: the str rep length of num
 * @base: use base to convert number
 * Return: @num as string in base @base
 */
char *convert_double_to_str(double num, unsigned int len, number_base_t base)
{
	const char *digits = "0123456789abcdef";
	long int int_part;
	double fractional_part;
	char *result = NULL;
	int j;

	if (len > 0)
	{
		result = malloc(sizeof(char) * (len + 1));
		if (result != NULL)
		{
			if (num < 0)
			{
				num *= -1.0;
				result[0] = '-';
			}
			int_part = (long int)num;
			fractional_part = num - (double)int_part;
			j = len - 1;
			do {
				fractional_part *= (double)base;
				result[j] = digits[(int)fractional_part];
				j++;
				fractional_part = fractional_part - (double)((long int)fractional_part);
			} while (fractional_part > 0);
			result[j] = '.';
			j++;
			do {
				result[j] = digits[int_part % (int)base];
				int_part /= (int)base;
				j++;
			} while (int_part > 0);
		}
	}
	return (result);
}

