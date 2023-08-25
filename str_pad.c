#include "main.h"
#include <stdlib.h>
/**
 * pad_left - pad str to left with pad char
 * @pstr: string to pad
 * @str_len: current length of str
 * @w: desired length
 * @pad: padding char
 * Return: void
 */
void pad_left(char **pstr, const int str_len, const int w, const char pad)
{
	char *temp;
	int i, j;

	if (w > str_len)
	{
		temp = malloc(sizeof(char) * (w + 1));
		if (temp != NULL)
		{
			for (i = 0; i < (w - str_len); ++i)
				temp[i] = pad;
			for (j = 0; i < w && j < str_len; ++j, ++i)
				temp[i] = (*pstr)[j];
			temp[i] = '\0';
			free(*pstr);
			*pstr = temp;
		}
	}
}
/**
 * pad_right - pad str to right with char
 * @pstr: string to pad
 * @str_len: current length of str
 * @w: desired length
 * @pad: pad char
 * Return: void
 */
void pad_right(char **pstr, const int str_len, const int w, const char pad)
{
	char *temp;
	int i, j;

	if (w > str_len)
	{
		temp = malloc(sizeof(char) * (w + 1));
		if (temp != NULL)
		{
			for (i = w - 1; i >= str_len; --i)
				temp[i] = pad;
			for (j = str_len - 1; i >= 0 && j >= 0; --i, --j)
				temp[i] = (*pstr)[j];
			temp[w] = '\0';
			free(*pstr);
			*pstr = temp;
		}
	}
}
/**
 * _prepend - prepend app in front of str
 * @str: string
 * @str_len: str length
 * @app: string
 * @app_len: app length
 * Return: void
 */
void _prepend(char **str, const int str_len, const char *app,
		const int app_len)
{
	char *temp;
	int i, j;

	if (str != NULL)
	{
		temp = malloc(sizeof(char) * (str_len + app_len + 1));
		if (temp != NULL)
		{
			for (i = 0; i < app_len; ++i)
				temp[i] = app[i];
			for (j = 0; j < str_len; ++j, ++i)
				temp[i] = (*str)[j];
			temp[i] = '\0';
			free(*str);
			*str = temp;
		}
	}
}

