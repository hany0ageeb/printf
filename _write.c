#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _write_char - write a char to buffer
 * @index: the index of the next write to buffer
 * @c: char to write
 * @buffer: write buffer
 * @buffer_size: max char that buffer can hold
 * Return: number of char written
 */
int _write_char(char *buffer, unsigned int *index,
		unsigned int buffer_size, const char c)
{
	int count = 0;

	if (buffer != NULL)
	{
		if ((*index) < buffer_size)
		{
			buffer[*index] = c;
			(*index)++;
			buffer[*index] = '\0';
		}
		else
		{
			count += write(STDOUT_FILENO, buffer, buffer_size);
			(*index) = 0;
			buffer[*index] = c;
			(*index)++;
			buffer[*index] = '\0';
		}
	}
	else
	{
		buffer = malloc(sizeof(char) * 2);
		if (buffer != NULL)
		{
			buffer[0] = c;
			buffer[1] = '\0';
			count += write(STDOUT_FILENO, buffer, 2);
			free(buffer);
			buffer = NULL;
		}
	}
	return (count);
}
/**
 * _write_str - write string to stdout
 * @buffer: the buffer
 * @index: index
 * @buffer_size: buffer size
 * @data: data to write
 * Return: number of chars written
 */
int _write_str(char *buffer, unsigned int *index,
		unsigned int buffer_size, const char *data)
{
	int count = 0;

	if (buffer != NULL)
	{
		if (data != NULL)
		{
			while (*data != '\0')
			{
				if (*index < buffer_size)
				{
					buffer[*index] = *data;
					(*index)++;
					buffer[*index] = '\0';
				}
				else
				{
					count += write(STDOUT_FILENO, buffer, buffer_size);
					*index = 0;
					buffer[*index] = '\0';
				}
				data++;
			}
		}
	}
	else
	{
		count += write(STDOUT_FILENO, data, _strlen(data));
	}
	return (count);
}

/**
 * _flush - flush the buffer
 * @buffer: buffer
 * @buffer_size: buffer size
 * Return: number of char written
 */
int _flush(char *buffer, unsigned int buffer_size)
{
	int count;

	if (buffer != NULL)
	{
		count = write(STDOUT_FILENO, buffer, buffer_size);
		buffer[0] = '\0';
	}
	return (count);
}

