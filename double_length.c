#include "main.h"
/**
 * double_length - a function to count number of digits in
 * double accounting minus & .
 * @num: number
 * @base: num base (2, 8, 10, 16)
 * Return: length of num
 */
long int double_length(double num, number_base_t base)
{
	long int len = 0;
	long int int_part;
	double fract_part;

	if (num < 0)
	{
		len++;
		num *= -1.0;
	}
	int_part = (long int)num;
	do {
		len++;
		num /= (int)base;
	} while (int_part > 0);
	len++;
	fract_part = num - int_part;
	if (fract_part > 0)
	{
		do {
			len++;
			fract_part *= (double)base;
		} while (fract_part > 0);
	}
	else
	{
		len++;
	}
	return (len);
}

