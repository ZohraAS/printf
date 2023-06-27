#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/**
 * _printf - printf function
 *
 * @format: format
 *
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	int ch;
	char *str;
	int num;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					putchar(ch);
					printed_chars++;
					break;
				case 's':
					str = va_arg(args, char *);
					fputs(str, stdout);
					printed_chars += strlen(str);
					break;
				case '%':
					putchar('%');
					printed_chars++;
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					printed_chars += printf("%d", num);
					break;
				case 'u':
					num = va_arg(args, unsigned int);
					printed_chars += printf("%u", num);
					break;
				case 'o':
					num = va_arg(args, unsigned int);
					printed_chars += printf("%o", num);
					break;
				case 'x':
				case 'X':
					num = va_arg(args, unsigned int);
					printed_chars += printf("%x", num);
					break;
				default:
					putchar('%');
					putchar(*format);
					printed_chars += 2;
					break;
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
