#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
 * _printf - custom printf function
 * @format: the format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count;
int c;
char *str;
count = 0;
va_start(args, format);
while (format && *format)
{
if (*format == '%' && *(format + 1))
{
format++;
if (*format == 'c')
{
c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (*format == 's')
{
str = va_arg(args, char *);
if (str)
{
while (*str)
{
write(1, str, 1);
count++;
str++;
}
}
else
{
write(1, "(null)", 6);
count += 6;
}
}
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
}
else
{
write(1, format, 1);
count++;
}
format++;
}
va_end(args);
return (count);
}
