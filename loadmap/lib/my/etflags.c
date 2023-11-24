/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-florian.dajon
** File description:
** etflags
*/
#include "../../include/my.h"
#include <stdarg.h>

int fflag(char const *str, va_list *ap, int size)
{
    double i = va_arg(*ap, double);
    int j = my_count_float(i, 6);
    int k = 0;
    (void) str;
    for (int l = 0; l < (size - j); l++)
        k += my_putchar(' ');
    return my_put_float(i, 6) + k;
}

int xflag(char const *str, va_list *ap, int size)
{
    int i = va_arg(*ap, int);
    int j = my_count_base(i, "0123456789ABCDEF");
    int k = 0;
    (void) str;
    for (int l = 0; l < (size - j); l++)
        k += my_putchar(' ');
    return my_putnbr_base(i, "0123456789ABCDEF") + k;
}

int len_detector(char const *str)
{
    int size = 0;
    if (stepper_condition(str[0]) == 0)
        size = my_getnbr(str);
    return size;
}
