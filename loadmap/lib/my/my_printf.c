/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-miniprintf-florian.dajon
** File description:
** mini_printf
*/
#include "../../include/my.h"
#include <stdlib.h>
#include <stdarg.h>

int stepper(char const *str)
{
    int i = 1;
    while (stepper_condition(str[i]) == 0)
        i++;
    return i;
}

int stepper_condition(char c)
{
    if (c == 's' || c == 'c' || c == 'i')
        return 1;
    if (c == 'd' || c == 'S' || c == 'b')
        return 1;
    if (c == 'f' || c == 'x' || c == 'X')
        return 1;
    return 0;
}

int flagdot(char const *str, va_list *ap)
{
    int i = my_getnbr(str + 1);
    double arg = va_arg(*ap, double);
    if (str[0] != '.')
        return 0;
    return my_put_float(arg, i);
}

int my_put_args(char const *str, va_list *ap, int size)
{
    char fs[] = {'s', 'c', 'i', 'd', 'S', 'b', 'f', 'x', 'X', '\0'};
    fc ff[] = {&sflag, &cflag, &iflag, &iflag, &upsflag, &bflag, &fflag, \
        &xflag, &xflag, NULL};

    for (int i = 0; fs[i]; i++) {
        if (str[0] == fs[i])
            return ff[i](str, ap, size);
    }
    return 1;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int y = 0;
    int size;
    va_start(ap, format);
    for (; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] == '.') {
            i += 2;
            y += flagdot(format + i - 1, &ap);
            i += 2;
        }
        if (format[i] == '%' && format[i + 1] != '.') {
            size = len_detector(format + i + 1);
            i += stepper(format + i);
            y += my_put_args(format + i, &ap, size);
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
    return i + y;
}
