#include "main.h"
/**
 * int_length - a function to count number of digits in a given number.
 * @num: integer number
 * @base: base of num (2, 8, 10, 16)
 * Return: num digits count
 */
long int int_length(long int num, number_base_t base)
{
	long int len = 0;

	if (num < 0)
	{
		len++;
		num *= -1;
	}
	do {
		len++;
		num /= (int)base;
	} while (num > 0);
	return (len);
}

