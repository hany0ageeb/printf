#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#define BUFFER_SIZE 1024
/**
 * enum number_base - Number system bases
 * @binary: base 2
 * @octal: base 8
 * @decimal: base 10
 * @hexadecimal: base 16
 */
typedef enum number_base
{
	binary = 2,
	octal = 8,
	decimal = 10,
	hexadecimal = 16
} number_base_t;
/**
 * struct conversion_specification - holds _printf conversion spec
 * @flag: conversion flag
 * @width: print width
 * @percision: percision
 * @length_modifier: length modifier
 * @conversion_specifier: conversion specifier.
 * @handler: conversion specifier handler
 */
typedef struct conversion_specification
{
	char *flag;
	int width;
	int percision;
	char *length_modifier;
	char conversion_specifier;
	char *(*handler)(const struct conversion_specification *spec, va_list argptr);
} conversion_specification_t;
char *concate_str(const char *str1, const char *str2);
unsigned int _strlen(const char *str);
char *sub_string(const char *src, unsigned int start, unsigned int end);
void _to_upper(char *str);
char *copy_str(const char *src, unsigned int len);
void reverse_str(char *str);
long int int_length(long int num, number_base_t base);
long int double_length(double num, number_base_t base);
char *convert_double_to_str(double num, unsigned int len, number_base_t base);
char *convert_int_to_str(long int num, unsigned int len, number_base_t base);
char *convert_uint_to_str(unsigned long int num, unsigned int len,
		number_base_t base);
int str_to_int(const char *str, int start, int end);
int last_index_of(const char *str, unsigned int l,
		unsigned int h, const char *sch);
int index_of(const char *str, unsigned int l, unsigned int h, const char *sch);
int contains_char(const char *str, const char c);
char *pad_left(const char *str, long int width, const char pad);
char *pad_right(const char *str, long int width, const char pad);
int _write_char(char *buffer, unsigned int *index,
		unsigned int buffer_size, const char c);
int _write_str(char *buffer, unsigned int *index,
		unsigned int buffer_size, const char *data);
void free_specification(conversion_specification_t *pspec);
conversion_specification_t *interpret_specification(const char *format,
		int start, int end);
int _flush(char *buffer, unsigned int buffer_size);
char *handle_c_specifier(const conversion_specification_t *specification,
		va_list argptr);
char *handle_s_specifier(const conversion_specification_t *specification,
		va_list argptr);
char *handle_per_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_d_i_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_o_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_x_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_u_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_p_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_b_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_S_specifier(const conversion_specification_t *spec,
		va_list argptr);
char *handle_r_specifier(const conversion_specification_t *spec,
		va_list argptr);
long int handle_length_for_unsigned(
		const conversion_specification_t *spec,
		va_list argptr);
long int handle_len_mod_for_signed(const conversion_specification_t *spec,
		va_list argptr);
void set_spec_handler(conversion_specification_t *spec);
int _printf(const char *format, ...);
#define CONVERSION_SPECIFIERS "rScsdibuoxX%"
#define CONVERSION_FLAGS "#0 +-"
#define LENGTH_MODIFIERS "lh"
#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
void _to_upper(char *str);
#endif

