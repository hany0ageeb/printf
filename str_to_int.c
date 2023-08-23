/**
 * str_to_int - convert string to int
 * @str: the string to convert
 * @start: start index
 * @end: end index
 * Return: the number
 */
int str_to_int(const char *str, int start, int end)
{
	int base = 1, val = 0;

	while (end >= start && end >= 0 && str[end] != '\0' &&
			str[end] >= '0' && str[end] <= '9')
	{
		val += (str[end] - 48) * base;
		base *= 10;
		end--;
	}
	return (val);
}
