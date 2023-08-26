#include "main.h"
#include <stdlib.h>
/**
 * int_len - calculate the number of digits
 * @num: integer number
 * @base: 2, 8, 10, 16 number system
 * Return: length of num
 */
int int_len(long int num, const num_base_t base)
{
	int len = 0;

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
/**
 * uint_len - get length of num
 * @num: number
 * @base: base
 * Return: length
 */
int uint_len(size_t num, const num_base_t base)
{
	int len = 0;

	do {
		len++;
		num /= (unsigned int)base;
	} while (num > 0);
	return (len);
}
/**
 * uint_to_str - convert size_t to string
 * @num: number
 * @base: number bas system
 * Return: string
 */
char *uint_to_str(size_t num, const num_base_t base)
{
	const char *digits = "0123456789abcdef";
	int len = uint_len(num, base);
	char *num_str = malloc(sizeof(char) * (len + 1));
	int i = len - 1;

	if (num_str != NULL)
	{
		do {
			num_str[i] = digits[num % (int)base];
			num /= (unsigned int)base;
			i--;
		} while (num > 0);
	}
	return (num_str);
}
/**
 * int_to_str - convert int to string
 * @num: integer number
 * @base: number system 2, 8, 10, 16
 * Return: string rep for num
 */
char *int_to_str(long int num, const num_base_t base)
{
	const char *digits = "0123456789abcdef";
	int len = int_len(num, base);
	char *num_str = malloc(sizeof(char) * (len + 1));
	int i = len - 1;

	if (num_str != NULL)
	{
		if (num < 0)
		{
			num_str[0] = '-';
			num *= -1;
		}
		do {
			num_str[i] = digits[num % (int)base];
			num /= (int)base;
			i--;
		} while (num > 0);
	}
	return (num_str);
}
/**
 * str_to_int - convert str to num
 * @format: string containing a number
 * @l: start index
 * @h: end index
 * @base: number base
 * Return: int
 */
int str_to_int(const char *format, int l, int h, num_base_t base)
{
	int value = 0, weight = 1;

	if (format == NULL || *format == '\0' || h < l)
		return (0);
	while (h >= l)
	{
		if (format[h] >= '0' && format[h] <= '9')
		{
			value += (format[h] - 48) * weight;
			weight *= (int)base;
		}
		else
		{
			return (value);
		}
		h--;
	}
	return (value);
}

