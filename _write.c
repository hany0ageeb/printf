#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _write_str - write a string to std
 * @data: data to be written
 * @buffer: buffer
 * @max_buff_size: maximum buffer size
 * Return: char written count
 */
int _write_str(char *buffer, const char *data, const int max_buff_size)
{
	int count = 0;
	int i, j, data_len;

	if (data != NULL)
	{
		i = _strlen(buffer);
		j = 0;
		data_len = _strlen(data);
		if (data_len == 1 && data[0] == '\a')
			return (1);
		while (j < data_len)
		{
			if (i < max_buff_size)
			{
				buffer[i] = data[j];
				if (data[j + 1] == '\0')
					buffer[i + 1] = '\0';
				i++;
			}
			else
			{
				buffer[max_buff_size] = '\0';
				count += write(STDOUT_FILENO, buffer, max_buff_size);
				buffer[0] = data[j];
				if (data[j + 1] == '\0')
					buffer[1] = '\0';
				i = 1;
			}
			j++;
		}
	}
	return (count);
}
/**
 * _write_char - write a char to std
 * @c: char to be written
 * @buffer: buffer
 * @max_buff_size: maximum buffer size
 * Return: 1 if c was written other wise -1
 */
int _write_char(char *buffer, const char c, const int max_buff_size)
{
	char *str = malloc(sizeof(char) * 2);
	int count;

	if (str != NULL)
	{
		str[0] = c;
		str[1] = '\0';
	}
	count = _write_str(buffer, str, max_buff_size);
	free(str);
	return (count);
}
/**
 * _flush - flush buffer
 * @buffer: buffer
 * Return: written char count
 */
int _flush(char *buffer)
{
	int len = _strlen(buffer);
	int count = write(STDOUT_FILENO, buffer, len);

	buffer[0] = '\0';
	return (count);
}

