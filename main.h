#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
/**
 * enum number_base - number base system
 * @binary: binary number system base 2
 * @octal: base 8
 * @decimal: base 10
 * @hexadecimal: 16
 */
typedef enum number_base
{
	binary = 2,
	octal = 8,
	decimal = 10,
	hexadecimal = 16
} num_base_t;
/**
 * struct conv_spec - conversion specification
 * @width: width
 * @percision: percision
 * @specifier: specifier
 * @flag: flag
 * @len_mod: length modifier
 * @formatter: formatter function
 */
typedef struct conv_spec
{
	int width;
	int percision;
	char specifier;
	char *flag;
	char len_mod;
	char *(*formatter)(const struct conv_spec *pspec, va_list argptr);
} conv_spec_t;
char *_str(const char c, int len);
char *copy_str(const char *src);
void _to_upper(char *str);
int contains_char(const char *str, const char c);
int _strlen(const char *str);
char *cp_str(const char *str);
char *reverse_str(const char *str);
int last_index_of(const char *str, int start, int end, const char *sch);
int index_of(const char *str, int start, int end, const char *search);
char *sub_str(const char *str, int start, int end);
char *int_to_str(long int num, const num_base_t base);
void _prepend(char **, const int, const char *, const int);
void pad_left(char **pstr, const int str_len, const int w, const char pad);
void pad_right(char **pstr, const int str_len, const int w, const char pad);
int str_to_int(const char *format, int start, int end, num_base_t base);
char *handle_c_spec(const conv_spec_t *pspec, va_list argptr);
char *handle_s_spec(const conv_spec_t *pspec, va_list argptr);
char *handle_per_spec(const conv_spec_t *pspec, va_list argptr);
char *handle_d_spec(const conv_spec_t *pspec, va_list argptr);
char *handle_b_spec(const conv_spec_t *pspec, va_list argptr);
void handle_flag(char **, const char *, const char);
long int handle_len_mod(const char, const char, va_list);
void handle_width(char **, const conv_spec_t *);
char *handle_u_spec(const conv_spec_t *pspec, va_list argptr);
char *handle_S_spec(const conv_spec_t *spec, va_list argptr);
char *handle_p_spec(const conv_spec_t *spec, va_list argptr);
char *hanlde_r_spec(const conv_spec_t *spec, va_list argptr);
char *handle_R_spec(const conv_spec_t *spec, va_list argptr);
int is_valid_flag(const char *flag);
void set_conv_spec_formatter(conv_spec_t *pspec);
int tokenize(conv_spec_t **spec, const char *format,
		const int format_len, int pstart);
void free_conv_spec(conv_spec_t *pspec);
int _printf(const char *format, ...);
int _write_str(char *buffer, const char *data, const int max_buff_size);
int _write_char(char *buffer, const char c, const int max_buff_size);
int _flush(char *buffer);
#define BUFF_SIZE 1024
#define CONVERSION_SPECIFIERS "cs%dibuoxXSprR"
#define CONVERSION_FLAGS "+ #0-"
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1
#endif

