#include "main.h"
/**
 * reverse_str - reverse string in place
 * @str: a string to be reversed
 * Retunr: void
 */
void reverse_str(char *str)
{
	unsigned int len = _strlen(str);
	int i = 0, j = len - 1;
	char c;

	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

