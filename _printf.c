#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
int printed_chars = 0;

va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
int ch = va_arg(args, int);
putchar(ch);
printed_chars++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
fputs(str, stdout);
printed_chars += strlen(str);
}
else if (*format == '%')
{
putchar('%');
printed_chars++;
}
}
else
{
putchar(*format);
printed_chars++;
}
format++;
}
va_end(args);
return (printed_chars);
}
