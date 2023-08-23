#include "main.h"
#include <stdlib.h>
/**
 * convert_int_to_str - converts an int to its str rep
 * @num: number
 * @len: str rep length
 * @base: 2, 8, 10, 16
 * Return: num as char[] in base 'base'
 */
char *convert_int_to_str(long int num, unsigned int len, number_base_t base)
{
	const char *digits = "0123456789abcdef";
	char *result = NULL;
	int j;

	if (len > 0)
	{
		result = malloc(sizeof(char) * (len + 1));
		if (result != NULL)
		{
			if (num < 0)
			{
				num *= -1;
				result[0] = '-';
			}
			if (num < (int)base)
			{
				result[len - 1] = digits[num];
			}
			else
			{
				j = len - 1;
				do {
					result[j] = digits[num % (int)base];
					num /= (int)base;
					j--;
				} while (num > 0 && j >= 0);
			}
			result[len] = '\0';
		}
	}
	return (result);
}
/**
 * convert_uint_to_str - the same as uint only for unsigned
 * @num: unsigend int
 * @base: 2, 8, 10, 16
 * @len: length
 * Return: string
 */
char *convert_uint_to_str(unsigned long int num, unsigned int len,
		number_base_t base)
{
	const char *digits = "0123456789abcdef";
	char *result = malloc(sizeof(char) * (len + 1));
	int j = len - 1;

	if (result != NULL)
	{
		do {
			result[j] = digits[num % (int)base];
			num /= (int)base;
			j--;
		} while (num > 0 && j >= 0);
	}
	return (result);
}


