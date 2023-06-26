#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...);
int handle_conversion_specifier(const char *format, va_list args);

/**
 * _printf - printf function
 *
 * @format: format string
 *
 * Return: Number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += handle_conversion_specifier(format, args);
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * handle_conversion_specifier - Handle conversion specifier
 * @format: Format string
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int handle_conversion_specifier(const char *format, va_list args)
{
	int count = 0;
	char ch;
	const char *str;

	switch (*format)
	{
		case 'c':
			ch = (char) va_arg(args, int);
			putchar(ch);
			count++;
			break;
		case 's':
			str = va_arg(args, const char *);
			while (*str)
			{
				putchar(*str);
				str++;
				count++;
			}
			break;
		case '%':
			putchar('%');
			count++;
			break;
		default:
			putchar('%');
			putchar(*format);
			count += 2;
			break;
	}
	return (count);
}

