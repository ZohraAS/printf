#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int printed_chars = 0;
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
return printed_chars;
}
int main(void)
{
int count = _printf("Hello, %s! Today is %c%c%c.\n", "John", 'J', 'u', 'n');
printf("Printed characters: %d\n", count);
return 0;
}
