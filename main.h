#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
void _print_char(va_list args, int *count);
void _print_string(va_list args, int *count);
void _printed_decimal(va_list args, int *count);
void _print_percent(int *count);

#endif
